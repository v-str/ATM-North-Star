/* IWCS - Initial wid control sizes
Special class for storing initial wid parameters
iww_ - inital wid width
iwh_ - initial wid height
ifh_ - initial font height
ifps_ - initial font pixel size
ifch_ - initial font height coefficient
ifcw_ - initial font width coefficient
*/

#ifndef IWCS_H
#define IWCS_h

class IWCS {
 public:
  void SetIww(int iww);
  void SetIwh(int iwh);
  void SetIfps(int ifps);

  int Iww() const;
  int Iwh() const;
  int Ifps() const;
  int Ifch() const;
  int Ifcw() const;

 private:
  void SetIfch();
  void SetIfcw();

  int iww_ = 0;
  int iwh_ = 0;
  int ifps_ = 0;
  int ifch_ = 0;
  int ifcw_ = 0;

  static double kWidthMultiplier;
};

#endif  // IWCS_H
