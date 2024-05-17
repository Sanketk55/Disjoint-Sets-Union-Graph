#include<bits/stdc++.h>

class disjoint_set{
    private:
        std :: vector<int> rank;
        std :: vector<int> parent;
        std :: vector<int> size;

    public:
        disjoint_set(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);

            for(int i=0;i<=n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        // finding ultimate parent and supressing path
        int ultimate_parent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = ultimate_parent(parent[node]);
        }

        void union_by_rank(int u, int v){
            int ultParOfU = ultimate_parent(u);
            int ultParOfV = ultimate_parent(v);

            // Already in a same component 
            if(ultParOfU == ultParOfV) return ;

            if(rank[ultParOfU] < rank[ultParOfV]){
                parent[ultParOfU] = ultParOfV;
            }

            else if(rank[ultParOfU] > rank[ultParOfV]){
                parent[ultParOfV] = ultParOfU;
                
            }
            else{
                parent[ultParOfU] = ultParOfV;
                rank[ultParOfU]++;
            }

        }

        void union_by_size(int u, int v){
            int ultParOfU = ultimate_parent(u);
            int ultParOfV = ultimate_parent(v);

            if(ultParOfU == ultParOfV) return ;
            if(size[ultParOfU] < size[ultParOfV]) {
                parent[ultParOfU] = ultParOfV; 
                size[ultParOfU] += size[ultParOfU]; 
            }
            else {
                parent[ultParOfV] = ultParOfU;
                size[ultParOfU] += size[ultParOfV]; 
            }

        }

};

