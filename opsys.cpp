#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <string>
using namespace std;

void print(std::string par,std::string child){
    cout<<par <<": "<<getppid()<<"\t"
    <<child<<": "<<getpid()<<endl;
}
int main() {

    if (fork() == 0) {
        print("P0", "P1");
    } else {
wait(nullptr);
        if(fork()!=0){
            wait(nullptr);
            print("kate","p0");
        }else{
            if(fork()==0){
            print("p2","p21");
            if(fork()==0){

                print("p21","p211");
            }
            }else{

                print("p0","p2");
            }
        }
    }

    }
