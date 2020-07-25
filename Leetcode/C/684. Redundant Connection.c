/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 */

int pre[1001]={0};
int find_tail(int node){
    int root=node,
        tmp;
    while(node != pre[node])   
        node = pre[node]; //当前节点非tail，就找pre节点
    
    while(root != node){   //当前节点到tail前一个節点
        tmp=pre[root];
        pre[root]=node; //路過的都存入tail
        root=tmp;
    }
    return node;
}

// void unionSet(int root1,int root2){
//     int x=find(root1);
//     int y=find(root2);
//     if(x!=y) pre[x]=y;   //合并根节点
//     return;
// }

/*
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
*/
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int x,y;
    int *ret=(int*)malloc(2*sizeof(int));
    for(int i=0; i<=edgesSize ; i++)  
        pre[i]=i; //每條邊的根節點先記錄自己
    
    for(int i=0;i<edgesSize;i++){
        x=find_tail(edges[i][0]);
        y=find_tail(edges[i][1]);
        if(x!=y) pre[x]=y;  //紀錄tail(edge指向節點)
        else{   //e.g. 1的tail是4,edge又指向4
            ret[0]=edges[i][0];
            ret[1]=edges[i][1];
        }
    }
    *returnSize=2;
    return ret;
}
