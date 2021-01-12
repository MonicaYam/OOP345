#include <fstream>
#include <algorithm>

#include "LineManager.h"
#include "Utilities.h"

using namespace std;
LineManager::LineManager(const std::string& fileName, std::vector<Workstation*>& ws, std::vector<CustomerOrder>& orders){
    Utilities u;
    u.setDelimiter('|');    
    string line, first, second;
    bool more = true, find = false;
    size_t currentPos = 0;

    ifstream file(fileName);

    if (!file){
        throw string("Unable to open [") + fileName + "] file.";
    }

    while(!file.eof()){
        string line;
        getline(file, line);
        first = u.extractToken(line, currentPos, more);

        if(more){
            second = u.extractToken(line, currentPos, more);
        }

        for(size_t i = 0; i < ws.size() && !find; ++i){
            if(ws[i]->getItemName() == first){
                if(!second.empty())
                {
                   for(size_t k = 0; k < ws.size() && !find; ++k){
                        if(ws[k]->getItemName()== second){
                                ws[i]->setNextStation(*ws[k]);
                                find = true;
                        }
                   }
                }

                AssemblySortedLine.push_back(ws[i]);
            }
        }

        currentPos = 0;
        find = false;
        first.clear();
        second.clear();
    }

    file.close();

    for(auto& co : orders){
        ToBeFilled.push_back(move(co));
    }

    AssemblyLine = ws;
    m_cntCustomerOrder = orders.size();
}

bool LineManager::run(ostream& os)
{
    os << "Line Manager Iteration: " << m_cntCallRun << endl;
 
    if(!ToBeFilled.empty()){
       *AssemblySortedLine[0] += move(ToBeFilled.front());
       ToBeFilled.pop_front();
    }

    for(Workstation* ws : AssemblyLine){
	ws->runProcess(os);
    }

    CustomerOrder temp;
    for(Workstation* ws : AssemblyLine){
	ws->moveOrder();

	if(ws->getIfCompleted(temp)){
	    Completed.push_back(move(temp));
	}
    }
    m_cntCallRun++;
    return Completed.size() == m_cntCustomerOrder;

}

void LineManager::displayCompletedOrders(ostream& os) const
{
    if(!Completed.empty()){
	for(auto& i: Completed){
	    i.display(os);
	}
    }
}

void LineManager::displayStations() const
{
	for(auto& i: AssemblyLine){
	    i->display(cout);
	}
}

void LineManager::displayStationsSorted() const
{
    for (auto i : AssemblySortedLine) {
        i->display(cout);
    }
}
