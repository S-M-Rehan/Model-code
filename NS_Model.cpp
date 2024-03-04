#include<iostream>
#include<vector>
#include<random>

using namespace std;

//function to initailize Road
vector<int> initializeRoad(int length)
{
    vector<int> road(length, 0);
    
    //place a car at a random place
    road[rand() % length ] = 1;
    return road;

}


//function to update the road based on the NS rules
void updateRoad(vector<int>& road)
{
    //copy the current state to apply updates
    vector<int> newRoad = road;

    for (int i = 1; i < road.size()-1; ++i)
    {
        if (road[i] == 1 && road[i+1] == 0)
        {
            //A car moves forward if th cell inftont is empty
            newRoad[i] = 0;
            newRoad[i+1] = 1;
        }
        else if (road[i] == 1 && road[i+1] == 1 && road[i+2] == 0)
        {
            //car moves forward if teh cell infront is moving and teh cell after that is empty
            newRoad[i] = 0;
            newRoad[i+1] = 1;
        }
        else if (road[i] = 2 && road[i+1] == 0)
        {
            // a car starts moving if the cell infont is empty
            newRoad[i] = 0;
            newRoad[i+1] = 1;
        }

        road = newRoad;//update teh new road
        
        
        
    }
    
}

void PrintRoad(const vector<int> & road)
{
    for (int cell: road )
    {
        cout<<cell<<" ";
    }
    cout<<endl;

    
}


int main()
{
    //length of the road
    int roadLength = 20;

    //number of the iterations to simulate
    int iterations = 50;

    vector<int> road = initializeRoad(roadLength);

    for (int  i = 0; i < iterations; ++i)
    {
        PrintRoad(road);
        updateRoad(road);
    }
    
    return 0;
}