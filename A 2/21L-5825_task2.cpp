#include <iostream>
using namespace std;

class MyPolynomial {
private:
    float* coeff_Array;
    float* degree_Array;
    int num_Terms; 

public:
    // constructor of the polynomial class.
    MyPolynomial(){
    	
    	coeff_Array=NULL;
    	degree_Array=NULL;
    	num_Terms=0;
    	
	}

    // destructor of the polynomial class.
    ~MyPolynomial() {
        delete[] coeff_Array;
        delete[] degree_Array;
    }

    // copy constructor of the polynomial class.
    MyPolynomial(const MyPolynomial& other) : num_Terms(other.num_Terms) {
        coeff_Array = new float[num_Terms];
        degree_Array = new float[num_Terms];

        int i = 0;
        while (i < num_Terms) {
            coeff_Array[i] = other.coeff_Array[i];
            degree_Array[i] = other.degree_Array[i];
            ++i;
        }
    }
    
        // overloading - operator for polynomial subtraction.
MyPolynomial operator-(const MyPolynomial& other) const {
    MyPolynomial final;

    final.num_Terms = num_Terms + other.num_Terms;
    final.coeff_Array = new float[final.num_Terms];
    final.degree_Array = new float[final.num_Terms];

    int i = 0, j = 0, k = 0;

    // merging and subtract the coefficients while considering the degrees of the polynomials.
    while (j < num_Terms && k < other.num_Terms) {
        if (degree_Array[j] > other.degree_Array[k]) {
            final.coeff_Array[i] = coeff_Array[j];
            final.degree_Array[i] = degree_Array[j];
            ++j;
            ++i;
        } else if (degree_Array[j] == other.degree_Array[k]) {
            final.coeff_Array[i] = coeff_Array[j] - other.coeff_Array[k];
            final.degree_Array[i] = degree_Array[j];
            ++j;
            ++k;
            
            if (final.coeff_Array[i] == 0.0) {
                --i;
            }
            ++i;
        } else {
            final.coeff_Array[i] = -other.coeff_Array[k];
            final.degree_Array[i] = other.degree_Array[k];
            ++k;
            ++i;
        }
    }

   
    while (j < num_Terms) {
        final.coeff_Array[i] = coeff_Array[j];
        final.degree_Array[i] = degree_Array[j];
        ++j;
        ++i;
    }


    while (k < other.num_Terms) {
        final.coeff_Array[i] = -other.coeff_Array[k];
        final.degree_Array[i] = other.degree_Array[k];
        ++k;
        ++i;
    }

    final.num_Terms = i; 

    
    int x = 0;
    while (x < final.num_Terms - 1) {
        int y = x + 1;
        while (y < final.num_Terms) {
            if (final.degree_Array[x] < final.degree_Array[y]) {
                swap(final.degree_Array[x], final.degree_Array[y]);
              
            }
            ++y;
        }
        ++x;
    }

    return final;
}
    
   // overloading comparison  == operator for checking whether a and b are equal or not.
    bool operator==(const MyPolynomial& other) const {
        
        if (num_Terms != other.num_Terms) {
            return false;
        }

      
        int i = 0;
        while (i < num_Terms) {
            if (coeff_Array[i] != other.coeff_Array[i] || degree_Array[i] != other.degree_Array[i]) {
                return false;
            }
            ++i;
        }

       
        return true;
    }
    
    
    
    
    //overloading the assignment operator =.
    MyPolynomial& operator=(const MyPolynomial& other) {
        if (this == &other) {
            return *this;
        }

        delete[] coeff_Array;
        delete[] degree_Array;

        num_Terms = other.num_Terms;
        coeff_Array = new float[num_Terms];
        degree_Array = new float[num_Terms];

        int i = 0;
        while (i < num_Terms) {
            coeff_Array[i] = other.coeff_Array[i];
            degree_Array[i] = other.degree_Array[i];
            ++i;
        }

        return *this;
    }



  // this function is used to print the polynomial  as required.
void print_polynomial() const {
   
    for (int i = 0; i < num_Terms - 1; ++i) {
        for (int j = 0; j < num_Terms - i - 1; ++j) {
            if (degree_Array[j] < degree_Array[j + 1]) {
                
                int temp_degree = degree_Array[j];
                degree_Array[j] = degree_Array[j + 1];
                degree_Array[j + 1] = temp_degree;

              
                double temp_coeff = coeff_Array[j];
                coeff_Array[j] = coeff_Array[j + 1];
                coeff_Array[j + 1] = temp_coeff;
            }
        }
    }

    bool first_term = true;
    for (int i = 0; i < num_Terms; ++i) {
        if (coeff_Array[i] != 0.0) {
            if (!first_term && coeff_Array[i] > 0.0) {
                cout << " + ";
            }
            if (coeff_Array[i] < 0.0) {
                cout << "- ";
            }

            double abs_coeff = (coeff_Array[i] >= 0.0) ? coeff_Array[i] : -coeff_Array[i];
            if (abs_coeff != 1.0 || degree_Array[i] == 0) {
                cout << abs_coeff;
            }

            if (degree_Array[i] > 0) {
                cout << "x";
                if (degree_Array[i] > 1) {
                    cout << "^" << degree_Array[i];
                }
            }

            first_term = false;
        }
    }

   
    if (first_term) {
        cout << "0";
    }

    cout << endl;
}





    // this function is used to input the polynomial from the user as required.
    void  inputting_Polynomial() {
        cout << "Enter the number of terms in the polynomial: ";
        cin >> num_Terms;
        
        if( num_Terms<0){
        	
        	cout<<"INVALID INPUT"<<endl;
        	cout<<"Enter a positive iteger as terms:"<<endl;
        	    cin >> num_Terms;
		}

        coeff_Array = new float[num_Terms];
        degree_Array = new float[num_Terms];

        cout << "Enter the coefficients and degrees of each term:"<<endl;
        int i = 0;
        
      
        while (i < num_Terms) {
            cout << "Coefficient " << i + 1 << ": ";
            cin >> coeff_Array[i];
      
            cout << "Degree " << i + 1 << ": ";
            cin >> degree_Array[i];
         
            ++i;
        }

        // for  sorting  the arrays in descending order of degrees.
        int j = 0;
        while (j < num_Terms - 1) {
            int k = j + 1;
            while (k < num_Terms) {
                if (degree_Array[j] < degree_Array[k]) {
                    swap(degree_Array[j], degree_Array[k]);
                   
                }
                ++k;
            }
            ++j;
        }
    }
    
      // overloading  * operator for polynomial multiplication of a and b.
    MyPolynomial operator*(const MyPolynomial& other) const {
        MyPolynomial final;

       
       final.num_Terms = num_Terms * other.num_Terms;
       final.coeff_Array = new float[final.num_Terms];
       final.degree_Array = new float[final.num_Terms];

    
        int i = 0;
        while (i <final.num_Terms) {
           final.coeff_Array[i] = 0.0;
           final.degree_Array[i] = 0.0;
            ++i;
        }

        // for performing  polynomial multiplication of a and b.
        i = 0;
        while (i < num_Terms) {
            int j = 0;
            while (j < other.num_Terms) {
               final.coeff_Array[i] += coeff_Array[i] * other.coeff_Array[j];
               final.degree_Array[i] = degree_Array[i] + other.degree_Array[j];
                ++i;
                ++j;
            }
        }

        // combining the similar terms.
        i = 0;
        while (i <final.num_Terms) {
            int j = i + 1;
            while (j <final.num_Terms) {
                if (final.degree_Array[i] ==final.degree_Array[j]) {
                   final.coeff_Array[i] +=final.coeff_Array[j];
                   final.coeff_Array[j] = 0.0;
                }
                ++j;
            }
            ++i;
        }

        // for sorting the array.
        int newTerms = 0;
        i = 0;
        while (i <final.num_Terms) {
            if (final.coeff_Array[i] != 0.0) {
               final.coeff_Array[newTerms] =final.coeff_Array[i];
               final.degree_Array[newTerms] =final.degree_Array[i];
                ++newTerms;
            }
            ++i;
        }

       final.num_Terms = newTerms;

   
        int x = 0;
        while (x <final.num_Terms - 1) {
            int y = x + 1;
            while (y <final.num_Terms) {
                if (final.degree_Array[x] <final.degree_Array[y]) {
                    swap(final.degree_Array[x],final.degree_Array[y]);
                   
                }
                ++y;
            }
            ++x;
        }

        return final;
    }
// overloading + operator for polynomial addition of both polynomial a and b.
MyPolynomial operator+(const MyPolynomial& other) const {
    MyPolynomial final;

    final.num_Terms = num_Terms + other.num_Terms;
    final.coeff_Array = new float[final.num_Terms];
    final.degree_Array = new float[final.num_Terms];

    int i = 0, j = 0, k = 0;

    // merging  and summing  the coefficients while considering the degrees of the polynomials.
    while (j < num_Terms && k < other.num_Terms) {
        if (degree_Array[j] > other.degree_Array[k]) {
            final.coeff_Array[i] = coeff_Array[j];
            final.degree_Array[i] = degree_Array[j];
            ++j;
        } else if (degree_Array[j] == other.degree_Array[k]) {
            final.coeff_Array[i] = coeff_Array[j] + other.coeff_Array[k];
            final.degree_Array[i] = degree_Array[j];
            ++j;
            ++k;
        } else {
            final.coeff_Array[i] = other.coeff_Array[k];
            final.degree_Array[i] = other.degree_Array[k];
            ++k;
        }
        ++i;
    }

    // for copying  the remaining terms from both polynomials if any left.
    while (j < num_Terms) {
        final.coeff_Array[i] = coeff_Array[j];
        final.degree_Array[i] = degree_Array[j];
        ++i;
        ++j;
    }

    while (k < other.num_Terms) {
        final.coeff_Array[i] = other.coeff_Array[k];
        final.degree_Array[i] = other.degree_Array[k];
        ++i;
        ++k;
    }

    final.num_Terms = i; // updating  the number of terms.

    // for sorting  the array in descending order of degrees of the polynomials.
    int x = 0;
    while (x < final.num_Terms - 1) {
        int y = x + 1;
        while (y < final.num_Terms) {
            if (final.degree_Array[x] < final.degree_Array[y]) {
                swap(final.degree_Array[x], final.degree_Array[y]);
                swap(final.coeff_Array[x], final.coeff_Array[y]);
            }
            ++y;
        }
        ++x;
    }

    return final;
}

    
 
};

int main() {
    MyPolynomial a, b, c;
    int option;
 // through do wile loop menu will be displayed each time and user can select a valid to perform the required action. 
    do {
        cout << "*********************MENU****************************" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Input the polynomial a from the user " << endl;
        cout << "2. Input the polynomial b from the user " << endl;
        cout << "3. Add a and b to give c" << endl;
        cout << "4. Multiply a and b to give c" << endl;
        cout << "5. Subtract a from b to give c " << endl;
        cout << "6. print_polynomial  a" << endl;
        cout << "7. print_polynomial  b" << endl;
        cout << "8. print_polynomial  c " << endl;
        cout << "9. Check a == b " << endl;
        cout << "*******************************************************" << endl;
        cout << endl;

        cout << "Please select an option from 0 to 9" << endl;
        cin >> option;
          //each time the user will a valid option the require valid option if statememnt will be perform a he will get the desired output.
        if (option == 0) {
            break;
            return 0;
        } else if (option < 0 || option > 9) {
            cout << "INVALID INPUT" << endl;
            cout << "Please enter a valid input from 0 to 9" << endl;
            continue;
        }

        if (option == 1) {
            cout << "Enter the values of polynomial A:" << endl;
            a. inputting_Polynomial();
        } else if (option == 2) {
            cout << "Enter the values of polynomial B:" << endl;
            b. inputting_Polynomial();
        } else if (option == 3) {
            c = a + b;
            cout << "Result  of C = A + B= ";
            c.print_polynomial ();
        } else if (option == 4) {
            c = a * b;
            cout << "Result of C = A * B= ";
            c.print_polynomial ();
        } else if (option == 5) {
            c = b - a;
            cout << "Result of C = B - A= ";
            c.print_polynomial ();
        } else if (option == 6) {
            cout << "The polynomial A entered is: ";
            a.print_polynomial ();
        } else if (option == 7) {
            cout << "The polynomial B entered is: ";
            b.print_polynomial ();
        } else if (option == 8) {
            cout << "The polynomial C entered is: ";
            c.print_polynomial ();
        } else if (option == 9) {
            if (a == b) {
                cout << "Polynomial A and B are the same." << endl;
            } else {
                cout << "Polynomial A and B are not the same." << endl;
            }
        }
    } while (option >= 0 && option <= 9);

    system("pause");
    return 0;
}

