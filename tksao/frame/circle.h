// Copyright (C) 1999-2016
// Smithsonian Astrophysical Observatory, Cambridge, MA, USA
// For conditions of distribution and use, see copyright notice in "copyright"

#ifndef __circle_h__
#define __circle_h__

#include "baseellipse.h"

class Circle : public BaseEllipse {
 protected:
  int fill_;

 protected:
  void renderXCircleDraw(Drawable, GC, Vector&, Vector&, int, int);
  void renderXEllipseDraw(Drawable, GC);

  void renderPSCircleDraw(Vector& cc, double l, float a1, float a2);
  void renderPSEllipseDraw();

#ifdef MAC_OSX_TK
  void renderMACOSXCircleDraw(Vector&, double, float, float);
  void renderMACOSXEllipseArcDraw(Vector&, Vector&, Vector&, Vector&);
#endif

#ifdef __WIN32
  void renderWIN32CircleDraw(Vector&, double, float, float);
  void renderWIN32EllipseArcDraw(Vector&, Vector&, Vector&, Vector&);
#endif

  void listNonCel(FitsImage*, ostream&, Coord::CoordSystem);

public:
  Circle(Base* p, const Vector& ctr, double r, int fill);
  Circle(Base* p, const Vector& ctr,
	 double r, int fill,
	 const char* clr, int *dsh,
	 int wth, const char* fnt, const char* txt, 
	 unsigned short prop, const char* cmt,
	 const List<Tag>& tg, const List<CallBack>& cb);
  Circle(const Circle&);

  virtual Marker* dup() {return new Circle(*this);}
  void edit(const Vector&, int);

  void rotateBegin() {}
  void rotate(const Vector& v, int h) {}
  void rotateEnd() {}

  void fill(int ff) {fill_ = ff;}
  int getFill() {return fill_;}

  void analysis(AnalysisTask, int);
  void analysisHistogram(char*, char*, int);
  void analysisPlot3d(char*, char*, Coord::CoordSystem, Marker::AnalysisMethod);
  void analysisStats(Coord::CoordSystem, Coord::SkyFrame sky);

  void list(ostream&, Coord::CoordSystem, Coord::SkyFrame, Coord::SkyFormat, int, int);
  virtual void listPost(ostream&, int, int);
  void listXML(ostream&, Coord::CoordSystem, Coord::SkyFrame, Coord::SkyFormat);
  virtual void listCiao(ostream&, Coord::CoordSystem, int);
  virtual void listSAOtng(ostream&, Coord::CoordSystem, Coord::SkyFrame, Coord::SkyFormat, int);
  virtual void listPros(ostream&, Coord::CoordSystem, Coord::SkyFrame, Coord::SkyFormat, int);
  virtual void listSAOimage(ostream&, int);

  // special composite funtionality
  void setComposite(const Matrix&, double);
};

#endif
