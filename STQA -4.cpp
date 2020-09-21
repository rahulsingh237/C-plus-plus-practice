#include<bits/stdc++.h>
using namespace std; 
float circle(){
float r;
cout<< "Enter Radius:- ";
cin>> r;
if (r < 1 || r > 100)
  {
cout<< "Out of Range";
    exit (0);
  }
float area = 3.14 * r * r;
return area;
}

float triangle ()
{
  float bs, h;
cout<< "Enter Base and Height:- ";
cin>> bs >> h;
  if (bs < 1 || bs > 100 || h < 1 || h > 100)
    {
cout<< "Out of Range";
      exit (0);
    }
  float area = 0.5 * bs * h;
  return area;
}

float square ()
{
  float s;
cout<< "Enter side:- ";
cin>> s;
  if (s < 1 || s > 100)
    {
cout<< "Out of Range";
      exit (0);
    }
  float area = s * s;
  return area;
}

float rectangle ()
{

  float l, b;
cout<< "Enter Length and Breadth:- ";
cin>> l >> b;
  if (l < 1 || l > 100 || b < 1 || b > 100)
    {
cout<< "Out of Range";
      exit (0);
    }
  float area = l * b;
  return area;
}

int main ()
{
  int ch;
  float area;
cout<< "Area of:\n 1. Circle\n 2. Square\n 3. Triangle\n 4. Rectangle";
cout<< "\nEnter Choice: ";
cin>>ch;
  switch (ch)
    {
    case 1:
      area = circle ();
cout<< "Area: " << area;
      break;
    case 2:
      area = square ();
cout<< "Area: " << area;
      break;
    case 3:
      area = triangle ();
cout<< "Area: " << area;
      break;
    case 4:
      area = rectangle ();
cout<< "Area: " << area;
      break;
    }
  return 0;
}

