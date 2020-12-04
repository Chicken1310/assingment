/* MY name : Mohamed saif aldeen
   Class : Second Year
   Department : Computer Engineering
*/

// import the input output stream liberary
#include<iostream>
// math library
#include<cmath>
// string library
#include<cstring>
using namespace std ;

//the base class (Shape)
class Shape {
  // protected scope to access it from derives(sup) classes only
  protected :
  // name for the shape
    char name[15] ;
    // pi initilaization for all classes
    float pi = 3.14159 ;
  // public scope to access it from any where
  public :
  // // virtual functions to let the compiler calculate the area and circumference from another same function in particuler shape
  virtual float circumference()= 0;
  virtual float area() =0;  // polymorphism
  //function to print the area
    void print_Area() {
      cout << "the area of the "<<name <<" is : "<<this->area() << '\n';
    }
    //function to print the circumference
    void print_Circumference() {
      cout <<"the circumference of the "<<name <<" is : "<< this->circumference() << '\n';
    }

};

// the Polygon class (base for Rec , Trgl and square)
class Polygon: public Shape {
  // private scope to use it for the Polygon class only
  private :
  // length of the side of the Polygon
  int l ;
  // number of sides of the Polygon
  int n ;
  protected :
  // declare width and height f
  float width ;
  float height ;
  public :
  // Empty constructor to initilaize shape name
  Polygon () {
    strcpy(name,"Polygon") ;
  }
  //  initilaize the length and the number of sides
  void set_sides(int a, int b) {l = a; n = b;}
  // set the values for the width and height
  void set_values(float a, float b)
  {
    width = a ;
    height = b ;
  }
  //function to initilaize the length and sides for the Polygon
  void enter() {
    std::cout << "Enter the length and the number of sides of the Polygon" << '\n';
    int n,l ;
    cin>>l>>n ;
    set_sides(l,n) ;
  }
  //calculate the area
    float area() {
      return ((l*l) * n / 4*tan(pi/n)) ;
    }
    //calculate the circumference
    float circumference() {
      return (n*l) ;
    }
    // function to simplify the input proccess
    void Enter () {
      int a ; int b ;
      cout << " Enter width and height of the shape : " << '\n';
      cin>>a>>b ;
      // this operator to refrence to the calling object (pointer)
      this->set_values(a,b) ;
    }


};


// Square class
class Square :public Polygon{
  public :
  // Empty constructor to initilaize shape name
  Square () {
    strcpy(name,"Square") ;
  }
    float area() {
      return (width*height) ;
    }

    float circumference() {
      return (4*width); // or 4*height
    }

};
// Rectangle
class Rectangle : public Polygon {
public:
  // Empty constructor to initilaize shape name
  Rectangle () {
    strcpy(name,"Rectangle") ;
  }
  float area() {
    return (width*height) ;
  }
  float circumference() {
    return (2*width+2*height) ;
  }

};

//Triangle class
class Triangle : public Polygon  {
public:
  // Empty constructor to initilaize shape name
  Triangle () {
    strcpy(name,"Triangle") ;
  }
  // declare sides of triangle to calculate the circumference
  int s1 = 0 ;
  int s2 = 0 ;
  int s3 = 0 ;
  void set_sides(int a, int b, int c) {s1 = a; s2=b; s3=c;}
  void enter() {
    std::cout << "Enter the sides of the triangle" << '\n';
    int s1, s2, s3 ;
    cin>>s1>>s2>>s3 ;
    set_sides(s1,s2,s3) ;
  }
  float area() {
    return (width*height/2) ;
  }
  float circumference() {
    return (s1+s2+s3) ;

  }

};

// Ellipse class (base class for circle)
class Ellipse : public Shape {
  // radius variables protected scope to use it with circle class only
  protected :
  float r1 ;
  float r2 ;
  public :
  // Empty constructor to get name
  Ellipse() {
    strcpy(name,"Ellipse") ; }
  void set_values (float a, float b) {r1 = a; r2= b ;}
  void enter() {
    std::cout << "Enter the radius of the Shape" << '\n';
    int a;int b ;
    // if statment to compare the names to initilaize the radius for circle or for the Ellipse
    if (not(strcmp(name,"Ellipse"))){
      cin>>a>>b;
      set_values(a,b) ;}
    else {
      cin>>a;
      set_values(a,a) ;}
  }
  //calculate the area
  float area() {
    return (pi*r1*r2) ;
  }
  //calculate the circumference
  float circumference() {
    return (2 * pi* sqrt((pow(r1,r1) + pow(r2,r2))) / (2*1.0)) ;
  }


};

//Circle class
class Circle : public Ellipse {
public :
//shape name
Circle () {
  strcpy(name,"Circle") ;
}
//calculate the area
float area() {
  return (pi*pow(r1,2))  ;
}
//calculate the circumference
float circumference() {
  return (2*pi*r1) ;
}

};

// main function
int main() {
  int num ;
  cout<<"Enter the number of shape you want calculate : "<<endl ;
  cout<<" 1/ Polygon\n 2/ Rectangle\n 3/ Square\n 4/ Triangle\n 5/ Ellipse\n 6/ Circle"<<endl ;
  // variable to get input from user
  cin >>num ;
  // if statment to proccess the user input and get the results
  // 1 for Polygon
  if (num == 1) {
    Polygon poly ;
    poly.enter() ;
    poly.print_Area() ;
    poly.print_Circumference() ;
  }
  // 2 for Rectangle
  else if (num == 2) {
    Rectangle rect ;
    Polygon *shape ;
    shape = &rect ;
    shape->Enter() ;
    shape->print_Area() ;
    shape->print_Circumference() ;
  }
  // 3 for Square
  else if (num == 3) {
    Square sqrt ;
    Polygon *shape ;
    shape = &sqrt ;
    shape->Enter() ;
    shape->print_Area() ;
    shape->print_Circumference() ;
  }
  // 4 for Triangle
  else if (num == 4) {
    Triangle trgl ;
    Polygon *shape ;
    shape = &trgl ;
    shape->Enter() ;
    shape->print_Area() ;
    trgl.enter() ;
    shape->print_Circumference() ;
  }
  // 5 for  Ellipse
  else if (num == 5) {
    Ellipse elp ;
    elp.enter() ;
    elp.print_Area() ;
    elp.print_Circumference() ;
  }
  // 6 for Circle
  else if (num == 6) {
    Circle crcl ;
    Ellipse *shape ;
    shape = &crcl ;
    crcl.enter() ;
    shape->print_Area() ;
    shape->print_Circumference() ;
  }

  return 0;
}
