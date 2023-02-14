#include <iostream>
#include <vector>

int main() {
    double m=0;
    int element;
    std::vector<int> elements;
    std::cin>>element;
    while(!std::cin.eof()){
        elements.push_back(element);
        std::cin>>element;
    }
    int n=elements.size();
    int count[n],max=0;
    for(int j=0; j<n; j++){
        count[j]=0;
        for (int i=0;i<n;i++){
            if(elements[i]==elements[j]){
                count[j]++;
            }
        if(count[j]>count[max])
            max=j;
        }
    
    }

    m=elements[max];
    std::cout<< "Mode: " << m << std::endl;
    return 0;
}