#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    int carsNum = routes.size();
    int cameraPoint = INT_MIN;
    
    #if 0
    answer = carsNum;
    
    int startPoint = INT_MAX;
    int endPoint = -1;    
    
    for(int idx = 0; idx < carsNum; ++idx)
    {
        if(startPoint > routes[idx][0])
        {
            startPoint = routes[idx][0];
        }
    }
    
    startPoint = abs(startPoint);
    
    for(int idx = 0; idx < carsNum; ++idx)
    {
        for(int point = 0; point < 2; ++point)
        {
            routes[idx][point] += startPoint;                    
        }
        
        if(routes[idx][1] > endPoint)
        {
            endPoint = routes[idx][1];
        }
    }
    
    vector<bool> route(endPoint + 1, false);
    
    for(int idx = 0; idx < carsNum; ++idx)
    {
        int startP = routes[idx][0];
        int endP = routes[idx][1];
        cout << "startP, endP: " << startP << ", " << endP << endl;
        for(int i = startP; i <= endP; ++i)
        {
            route[i] = true;
            cout << route[i] << endl;
        }
    }
    
    for(int idx = 0; idx <= endPoint; ++idx)
    {
        cout << route[idx] << " ";
    }
    #endif
    
    
    
    sort(routes.begin(), routes.end(), [](const vector<int> route1, const vector<int> route2)
         {
            return route1[1] < route2[1]; 
         });
    
    for(int idx = 0; idx < carsNum; ++idx)
    {
        int startP = routes[idx][0];
        int endP = routes[idx][1];
        
        if(cameraPoint < startP)
        {
            ++answer;
            cameraPoint = endP;
        }
    }
    
    
    return answer;
}