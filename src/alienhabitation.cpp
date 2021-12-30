#include "alienhabitation.h"
#include <vector>

using namespace std;

vector<vector<int>> calculateNewState(vector<vector<int>> inputState) {
	vector<vector<int>> ret(inputState);
	const int DIRX = {0, 1, 1, 1, 0, -1, -1, -1};
	const int DIRY = {1, 1, 0, -1, -1, -1, 0, 1};
	for(int i = 0; i < (int) inputState.size(); ++i) {
		for(int j = 0; j < (int) inputState[i].size(); ++j) {
			if(inputState[i] == 1) {
				int cnt = 0;
				for(int dir = 0; dir < 8; ++dir) {
					int i_dir = i + DIRY[dir];
					int j_dir = j + DIRX[dir];
					if(i_dir >= 0 && i_dir < (int) inputState.size() && j_dir >= 0 && j_dir < (int) inputState[i_dir].size()) {
						if(inputState[i_dir][j_dir] == 1) {
							cnt++;
						}
					}
				}
				if(cnt < 2 || cnt > 3) {
					ret[i][j] = 0;
				}
			}
		}
	}
	return ret;
}


