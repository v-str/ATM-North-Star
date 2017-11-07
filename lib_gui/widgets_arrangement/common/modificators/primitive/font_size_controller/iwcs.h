/* IWCS - Initial widget control sizes
Special class for storing initial widget parameters
iww_ - inital widget width
iwh_ - initial widget height
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
  void SetIfh(int ifh);
  void SetIfps(int ifps);
  void SetIfch(int ifch);
  void SetIfcw(int ifcw);

  int GetIww() const;
  int GetIwh() const;
  int GetIfh() const;
  int GetIfps() const;
  int GetIfch() const;
  int GetIfcw() const;

 private:
  int iww_ = 0;
  int iwh_ = 0;
  int ifh_ = 0;
  int ifps_ = 0;
  int ifch_ = 0;
  int ifcw_ = 0;
};

#endif  // IWCS_H
