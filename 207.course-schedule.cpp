class Solution {
public:
    // 类广度优先搜索
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> map(numCourses);
	vector<int> sign(numCourses, 0);

	for (int i=0; i<prerequisites.size(); ++i) {
	    map[prerequisites[i][0]].push_back(prerequisites[i][1]);
	    sign[prerequisites[i][1]]++;
	}

	int count_zero = 0;
	while (1) {
	    bool has_zero = false;
	    for (int i=0; i<numCourses; ++i) {
	        if (sign[i]==0) {
		    has_zero = true;
		    sign[i] = -1;
		    count_zero++;
		    for (int j=0; j<map[i].size(); ++j) {
		        --sign[map[i][j]];
		    }
		}
	    }
	    if (has_zero==false) break;
	}
	return count_zero==numCourses;
    }
    /*
    // 深度优先搜索
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> map(numCourses);
	vector<int> sign(numCourses, 0);

	for (int i=0; i<prerequisites.size(); ++i) {
	    map[prerequisites[i][0]].push_back(prerequisites[i][1]);
	}

	for (int k=0; k<numCourses; ++k) {
	    if (sign[k]==2) continue;
	    stack<int> dfs;
	    dfs.push(k);
	    while (!dfs.empty()) {
		int i = dfs.top();
		if (sign[i]==0) {
		    sign[i] = 1;
		    for (int j=0; j<map[i].size(); ++j) {
			if (sign[map[i][j]]==0) {
			    dfs.push(map[i][j]);
			}
			else if (sign[map[i][j]]==1) {
			    return false;
			}
		    }
		}
		else {
		    sign[i] = 2;
		    dfs.pop();
		}
	    }
	}
	return true;
    }
    */
};
