#include "Forma.h"

int main()
{
  cout << "\nPONTO NA FORMA PARA RETA R^3\n\n";
  cout << "p1 = p0 + t * vec_dir\n";
  cout << "t = (p1 - p0)/vec_dir\n";
  cout << "t será a(1,1,1) onde a pertence aos reais\n";

  //Coord p(-5,-4,3);   /* p1 belongs to line */
  Coord p(-3.0008, -7.0003, 8); /* p2 doesn't belongs to line */
  Coord p0(0, 0, 0);
  Coord vec_dir(5, 4, -3);

  cout << "p = " << p.print() << endl;
  cout << "p0 = " << p0.print() << endl;
  cout << "vec_dir = " << vec_dir.print() << endl;

  Coord t = (p - p0) / vec_dir;
  cout << "t = " << t.print() << endl;

  /* if A = B and B = C, A = C. Thus, A = B = C */
  bool A_equals_B = (t.get<Coord::x>() == t.get<Coord::y>());
  bool B_equals_C = (t.get<Coord::y>() == t.get<Coord::z>());

  /* operator AND (&&) because could be return true using EQUAL (==)
       if A_equals_B and B_equal_C are false. */
  bool A_equals_B_equals_C = (A_equals_B && B_equals_C);

  if (A_equals_B_equals_C == true)
  {
    double a = t.get<Coord::x>(); /* Could be y or z here (x = y = z) */
    cout << "\nPonto pertence a reta, pois esta na forma a(1,1,1)\n";
    cout << "Com a = " << a << "\n\n";

  }
  else
    cout << "\nPonto nao pertence a reta, pois nao esta na forma a(1,1,1)\n\n";

}