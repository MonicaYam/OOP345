#pragma once
#include<string>


#ifndef _SDDS_COLLECTION_H
#define _SDDS_COLLECTION_H

#include <iostream>
namespace sdds
{
	template <typename T>
	class Collection
	{
		std::string m_collectionName{};
		T* m_items = nullptr;
		size_t m_size = 0;
		void (*m_observer)(const Collection<T>&, const T&) = nullptr;

	public:
		/********** Constructor **************/
		Collection(std::string name) {
			m_collectionName = name;
		}

		~Collection() {
			if (m_items != nullptr) {
				delete[] m_items;
			}
		}

		Collection(const T& t) = delete;
		Collection& operator=(const T& t) = delete;
		Collection(const T&& t) = delete;
		Collection& operator=(const T&& t) = delete;


		/********** Return Member variable **************/
		const std::string& name() const {
			return m_collectionName;
		}
		size_t size() const {
			return m_size;
		}

		/********** overload operator += **************/
		Collection<T>& operator+=(const T& item) {
			bool found = false;
			for (int i = 0; i < (int)size() && !found; ++i) {
				if (m_items[i].title() == item.title()) {
					found = true;
				}
			}

			if (!found) {
				T* temp = new T[size() + 1];
				int k=0;
				for (k = 0; k < (int)size(); k++) {
					temp[k] = m_items[k];
				
				}
				m_size = k;
				temp[m_size++] = item;
				delete[] m_items;
				m_items = temp;

				if (m_observer != nullptr) {
					m_observer(*this, item);
				}
			}

			return *this;
		}


		/********** overload operator [] **************/
		T& operator[](size_t idx) const {
			if (0 > idx || idx >= size()) {
				throw std::out_of_range("EXCEPTION: Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.\n");
			}

			return  m_items[idx];
		}

		T* operator[](std::string title) const {
			T* temp = nullptr;
			for (int i = 0; i < (int)size() && temp == nullptr; i++) {
				if (m_items[i].title() == title) {
					temp = &m_items[i];
				}
			}

			return temp;
		}


		/********** setObserver **************/
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}

	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& c)
	{
		for (size_t i = 0; i < c.size(); i++) {
			os << c[i];
		}
		return os;
	}
}

#endif
