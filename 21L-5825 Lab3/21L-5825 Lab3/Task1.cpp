#include<iostream>
using namespace std;

class Tollbooth{
	
	private:
		int cars;
		double total_amount;
		
    public:
    	
    	
    	Tollbooth(){
    		
    		cars=0;
    		total_amount=0;}
    		
    	void payingCar(){
    		
    		cars++;
    		total_amount+=0.50;
    		
    		
		}	
    		
    	void noPaycar(){
    		
    		cars++;
		}
		
	void	display(){
			
			cout<<"The number of cars that have passed are:"<<cars<<endl;
			cout<<"The total amount is:"<<total_amount<<endl;
			
		}
		
		
};


int main(){
	
	Tollbooth obj;
	int num;
	cout<<"Enter 1 for paying car and 2 for non paying car and -1 to exit"<<endl;
	
	while(true){
		
		cin>>num;
		
		if(num==1){
			
			obj.payingCar();
		}
		
		if(num==2){
			
			obj.noPaycar();
		}
		
		if(num==-1){
			
			obj.display();
			
			break;
		}
	}
	
	 
	return 0;
}
