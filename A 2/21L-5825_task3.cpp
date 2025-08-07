#include<iostream>
using namespace std;

// forward class declaration to avoid any error.
class DM;
class DB{
	
	int feets;
	int inches;
	
	
	public:
		//  declaration of the parameterized constructor.
	DB(int f,int i){
		feets=f;
		inches=i;
	}
	
	// decalaration of the friend function.
	   friend DB add(DB, DM );
	
	
	// getters to return the final distance.
	int getfeets(){
		
		return feets;
	}
	
	int getinches(){
		
		return inches;
	}
};

class DM{
	
	int meters;
	int centimeters;
	
	public:
	// decalaration of the friend function.
		   friend DB add(DB, DM );
		   
	
	
		//  declaration of the parameterized constructor.	   
	DM(int m,int c){
		meters=m;
		centimeters=c;
	}
		};
		
		
 DB add(DB db,DM dm){
 	
 	// first conver the distance in Dm class in centimeters here t_c_DM variable will contain total number of centimeters.
    int t_c_DM = dm.meters * 100 + dm.centimeters;

    // now first we will convert the distance of DB in inches and store it in t_I_DB.
    int t_I_DB = (db.feets * 12) + db.inches;
    
    // now we will convert the inches of DB in centimeters.
    int t_c_DB = t_I_DB * 2.54;

    // now we will add centimeters of both the classes.
    int t_c_r = t_c_DM + t_c_DB;

    // now we will calculate feets by dividing total centimeters from (2.54 * 12).
    int f_r = t_c_r / (2.54 * 12);
    
      // now we will calculate inches by dividing total centimeters from  2.54 - f_r * 12.
    int i_r = t_c_r/ 2.54 - f_r * 12;


   // now we will return the total inches and feets;
    return DB(f_r, i_r);
 	
 	
 }		

 
int main()
{
    int mtrs, c_m, fets, inchs;
// first we take distances from the user in different scales.
    cout << "Enter the total  meters"<<endl; 
    cin >> mtrs ;
    
     cout << "Enter the total  centimeters"<<endl; 
    cin >> c_m ;
    

    DM dm(mtrs, c_m);
        cout << "Enter the total  feets"<<endl; 
        cin >> fets ;
         
        cout << "Enter the total  inches"<<endl; 
        cin >> inchs ;

    DB db(fets, inchs);
 // after passing the distances in there the respective objects we will create another object of DB class to get the final distance.
    DB final = add(db, dm);

    cout << "The final  distance is: " << final.getfeets() << " feets " << final.getinches() << " inches" << endl;

    return 0;
}



