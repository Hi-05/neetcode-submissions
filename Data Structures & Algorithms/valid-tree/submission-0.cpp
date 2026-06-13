class Solution {
     
    class Disjoint{

        private :
            vector<int> par ;
            vector<int> size ;
        public :
            Disjoint(int n){

                par.resize(n) ;
                size.resize(n) ;

                for(int i = 0; i < n; i++){

                    par[i] = i;
                    size[i] = 1;
                }
            }

            int findUPar(int node){

                if(node == par[node]){
                    return node ;
                }

                return par[node] = findUPar(par[node]) ;
            }

            void unionBySize(int u , int v){

                int par_u = findUPar(u) ;
                int par_v = findUPar(v) ;

                if(size[par_u] > size[par_v]){

                    par[par_v] = par_u ;
                    size[par_u] += size[par_v] ;
                }
                else{

                    par[par_u] = par_v ;
                    size[par_v] += size[par_u] ;
                }
            }
    };
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        Disjoint ds(n) ;

        for(int i = 0; i < edges.size() ; i++){

            int u = edges[i][0] ;
            int v = edges[i][1] ;

            int par_u = ds.findUPar(u) ;
            int par_v = ds.findUPar(v) ;

            if(par_u == par_v){
                return false ;
            }
            else{

                ds.unionBySize(u , v) ;
            }
        }

        int ulp = ds.findUPar(0) ;

        for(int i = 1; i < n; i++){

            if(ulp != ds.findUPar(i)){
                return false ;
            }
        }

        return true ;

    }
};
