//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> chains(n);
//    for (int i = 0; i < n; i++)
//        cin >> chains[i];
//
//    ::sort(chains.begin(), chains.end()); 
//
//    int cnt = 0;
//    int remainingChains = n;
//
//    while (true)
//    {
//        if (chains.size() == 1)
//            break;
//
//        chains[chains.size() - 2] += chains[chains.size() - 1];
//        chains.pop_back();
//        cnt++;
//        chains.front()--;
//
//        if (chains.front() == 0)
//        {
//            for (int i = 0; i < chains.size() - 1; i++)
//                chains[i] = chains[i + 1];
//            
//            chains.pop_back();
//        }
//    }
//
//    cout << cnt << endl;
//    return 0;
//}
