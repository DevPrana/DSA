#include<iostream>
#define MAX 5
using namespace std;

int max = 5;

class Dfs{
public:
    int time;
    int traversal_array[MAX], j=0;
    int adj[MAX][MAX];
    int visited[MAX], start_time[MAX], end_time[MAX];

    Dfs(){
        time = 0;
        for (int i = 0; i < MAX; i++){
            scanf("%d %d %d %d %d", &adj[i][0], &adj[i][1], &adj[i][2], &adj[i][3], &adj[i][4]);
        }
        cout << "List representation" << endl << endl;
        for (int i = 0; i < MAX; i++){
            cout << i << " --> ";
            for (int j = 0; j < MAX; j++){
                if(adj[i][j] == 1){
                    cout << j << " ";
                }
            }
            cout << endl;
        }
        
        cout << "Adjency matrix" << endl << endl;
        for (int i = 0; i < MAX; i++){
            for (int j = 0; j < MAX; j++){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    void traverse_dfs(int i){
        visited[i] = 1;
        traversal_array[j++] = i;
        start_time[i] = time++;

        for (int j = 0; j < MAX; j++){
            if(!visited[j] && adj[i][j]){
                printf("Tree edge: %d --> %d\n", i, j);
                traverse_dfs(j);
            }
            else{
                if(start_time[i] > start_time[j] && end_time[i] < end_time[j]){
                    printf("Back edge: %d --> %d\n", i, j);
                }else if(start_time[i] < start_time[j] && end_time[i] > end_time[j]){
                    printf("Forward edge: %d --> %d\n", i, j);
                }else if(start_time[i] > start_time[j] && end_time[i] > end_time[j] && adj[i][j]){
                    printf("Cross edges: %d --> %d\n", i, j);
                }
            }

            end_time[i] = time++;
        }
        
    }
    void dfs(){
        for (int i = 0; i < MAX; i++){
            visited[i] = 0;
            start_time[i] = 0;
            end_time[i] = 0;
        }

        for (int i = 0; i < MAX; i++){
            if(!visited[i]){
                traverse_dfs(i);
            }
        }
        cout << endl;

        for(int i = 0; i< MAX;i++){
            cout << traversal_array[i] << " ";
        }
    }

};

int main(){
    Dfs test;
    test.dfs();    
}