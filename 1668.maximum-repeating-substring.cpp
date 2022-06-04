class Solution {
  public:
    int maxRepeating(string sequence, string word) {
	/*
	int l1 = sequence.size(),l2 = word.size();
	int k_max = 0;
	for(int i=0;i<l1-l2+1;++i)
	{
	    int k = 0;
	    int j = i;
	    while(j<l1-l2+1)
	    {
		string sub = sequence.substr(j,l2);
		if(word==sub) k++;
		else break;
		j += l2;
	    }
	    if(k_max<k) k_max = k;
	}
	return k_max;
	*/
	//BM算法
	int l1 = sequence.size(), l2 = word.size();
	const char *s = sequence.c_str();
	const char *w = word.c_str();
	int k_max = 0;
	for (int j = 0; j < l1 - l2 + 1; ++j) {
	    int i = j;
	    int k = 0;
	    while (i < l1) {
		int index = indexBM(s, l1, w, l2, i);
                if (index == i) {
                    i += l2;
                    k++;
                    if (k > k_max)
                        k_max = k;
                } else
                    break;
            }
        }
        if (g) {
            free(g);
            g = NULL;
            size = 0;
        }
        return k_max;
    }

    int b[256] = {0};
    int *g = NULL;
    int size = 0;

    void buildBads(const char *t, int tLength, int bads[256]) {
	for (int i = 0; i < 256; ++i)
	    bads[i] = tLength;
	for (int i = 0; i < tLength; ++i)
	    bads[t[i]] = tLength - 1 - i;
    }

    void suffixes(const char *t, int tLength, int *suff) {
	suff[tLength - 1] = tLength;
	for (int i = tLength - 2; i >= 0; --i) {
	    int j = i;
	    while (j >= 0) {
		if (t[j] != t[tLength - 1 - i + j])
		    break;
		j--;
	    }
	    suff[i] = i - j;
	}
    }

    void buildGoods(const char *t, int tLength, int *goods) {
	int *suff = (int *)malloc(sizeof(int) * tLength);
	suffixes(t, tLength, suff);
	for (int i = 0; i < tLength; ++i) {
	    goods[i] = 2 * tLength - 1 - i;
	}
	int j = 0;
	for (int i = tLength - 1; i >= 0; --i) {
	    if (suff[i] == i + 1) {
		for (; j < tLength - 1 - i; ++j) {
		    if (goods[j] == 2 * tLength - 1 - j)
			goods[j] = 2 * tLength - 2 - i - j;
		}
	    }
	}
	for (int i = 0; i < tLength - 1; ++i) {
	    goods[tLength - 1 - suff[i]] = tLength - 1 - i + suff[i];
	}
	free(suff);
    }

    int indexBM(const char *s, int sLength, const char *t, int tLength,
		int pos) {
        if (sLength < tLength)
            return -1;
        if (!g) {
            buildBads(t, tLength, b);
            g = (int *)malloc(sizeof(int) * tLength);
            size = tLength;
            buildGoods(t, tLength, g);
        }
        if (size < tLength) {
            buildBads(t, tLength, b);
            free(g);
            g = (int *)malloc(sizeof(int) * tLength);
            size = tLength;
            buildGoods(t, tLength, g);
        }
        int i = tLength - 1;
        int j = pos + i;
        while (i >= 0 && j < sLength) {
            if (t[i] == s[j]) {
                i--;
                j--;
            } else {
                j += g[i] > b[s[j]] ? g[i] : b[s[j]];
                i = tLength - 1;
            }
        }
        if (i < 0)
            return j + 1;
        else
            return -1;
    }
};
