inline int diff(double lhs, double rhs) {
	if (lhs - eps < rhs && rhs < lhs + eps) return 0;
	return (lhs < rhs) ? -1: 1;
}

struct Point {
	double x, y;
	Point() {}
	Point(double aa, double bb) : x(aa), y(bb) {}
	bool operator == (const Point &rhs) const {
		return ((diff(x, rhs.x) == 0) && (diff(y, rhs.y) == 0));
	}
	const Point operator + (const Point &rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}
	const Point operator - (const Point &rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
	const Point operator * (double t) const {
		return Point((double)(x)*(double)(t), (double)(y)*(double)(t));
	}
};

inline double Slope(const Point &pp, const Point &qq) {
	return (qq.x - pp.x) ? (double)(qq.y - pp.y) / (double)(qq.x - pp.x) : INF;
}

struct Circle {
	Point center;
	double r;
	Circle() {}
	Circle(const Point &aa, double bb) : center(aa), r(bb) {}
};

struct Line {
	Point s, d;
	double a,b,c,m;
	Line() {}
	Line(const Point &aa, const Point &bb) {
		s = aa; d = bb; m = Slope(s,d);
		a = d.y - s.y; b = s.x - d.x;
		c = (s.y*(d.x-s.x)) - (s.x*(d.y-s.y));
	}
};

inline double DOT(const Point &pp, const Point &qq) {
	return (double)(pp.x)*(double)(qq.x) + (double)(pp.y)*(double)(qq.y);
}
inline double CROSS(const Point &pp, const Point &qq) {
	return (double)(pp.x)*(double)(qq.y) - (double)(pp.y)*(double)(qq.x);
}
inline bool OnLine(const Point &pp, const Point &rr, const Point &qq) {
	return diff(CROSS(qq - pp, rr - pp), 0) == 0;
}
inline bool IsBetween(const double &pp, const double &rr, const double &qq) {
	return (diff(qq , max(pp, rr))<=0) && (diff(qq, min(pp , rr))>=0);
}
inline bool OnSegment(const Point &pp, const Point &rr, const Point &qq) {
	return OnLine(pp, rr, qq) && IsBetween(pp.x, rr.x, qq.x) && IsBetween(pp.y, rr.y, qq.y);
}
inline double dist(const Point &pp, const Point &qq) {
	return double(sqrt(DOT(pp - qq, pp - qq)));
}
Point LineIntersection(const Line &pp,const Line &qq) {
    double a1, a2;
    a1 = (((pp.b*qq.c)-(qq.b*pp.c))/((pp.a*qq.b)-(qq.a*pp.b)));
    a2 = (((pp.c*qq.a)-(qq.c*pp.a))/((pp.a*qq.b)-(qq.a*pp.b)));
    return Point(a1,a2);
}
double AreaOfPolygon(vector < Point > l, int n) {
    double pp = 0 ,qq = 0;
    for(int i=0;i<n;i++) {
        pp += (double)(l[i].x)*(double)(l[(i+1)%n].y);
        qq += (double)(l[(i+1)%n].x)*(double)(l[i].y);
    }
    double ans = (pp-qq); ans = abs(ans); ans/=2;
    return ans;
}
double AngleBetweenLines(const Line &pp , const Line &qq) {
    double CA = atan2(pp.d.y-pp.s.y , pp.d.x-pp.s.x);	// tc with directions
	double CB = atan2(qq.d.y-qq.s.y , qq.d.x-qq.s.x); 
	double c_ang = CA-CB; if(c_ang > PI) c_ang -= 2*PI;
	if(c_ang < -PI) c_ang += 2*PI;		// result - [-PI , PI]
	c_ang *= (ld)(180)/(ld)(PI); 
	if(diff(c_ang , 360.0) >= 0) c_ang-=360.0;
	if(diff(c_ang , 0.0) < 0) c_ang+=360.0;
	return c_ang;						// result clockwise and [0 , 360)
}

bool IsPointInsidePolygon(Point p ,vector <Point> pts ,int n) {
    for(int i=0;i<n;i++) { if(OnSegment(pts[i],pts[(i+1)%n],p)) { return 1; } }	// on polygon
  	int c1 = 0; double x1 , x2 , k , m , y2 , by;
    for(int i=0;i<n;i++) {
        if(diff(pts[i].x , pts[(i+1)%n].x) < 0) {
            x1 = pts[i].x;
            x2 = pts[(i+1)%n].x;
        }
        else { x1 = pts[(i+1)%n].x; x2 = pts[i].x; }
        if(diff(p.x, x1) > 0 && diff(p.x, x2) <= 0 && (diff(p.y, pts[i].y) < 0 || diff(p.y, pts[(i+1)%n].y) <= 0)) {
                Point d = pts[(i+1)%n] - pts[i];
                if(diff(d.x , d,y)==0) k = INF;
                else k = dy/dx;
                m = pts[i].ss - k * pts[i].ff;
                y2 = k * p.ff + m;
                by = (double)(p.ss);
                if(diff(by , y2) <= 0)  c1++;
        }
    }
    return c1&1;
}
----------------------------------------------------------------------------------------------------------------------------------

// geometric USES

struct point {
	double x , y ;
} p[N] ;

typedef point Vector ;

int dcmp(double a) {
	if(fabs(a)<1e-8	) return 0 ;
	return a>0 ? 1 : -1 ;
}

Vector operator - (point a,point b) {
	return Vector{a.x-b.x,a.y-b.y} ;
}

double cross(Vector u,Vector v) {
	return u.x*v.y - u.y*v.x ;
}

double dot(Vector u,Vector v) {
	return u.x*v.x + u.y*v.y ;
}

double length(Vector u) {
	return sqrt(dot(u,u)) ;
}

double angle(point a,point b,point c) {
	double la=length(a-b) , lb=length(a-c) , lc=length(c-b) ,t ;
	t = (la*la+lb*lb-lc*lc)/(2*la*lb) ;
	return acos(t) ;
}

double area(point a,point b,point c) {
	return fabs(cross(a-b,c-b))/2 ;
}

double seg(point P,Vector u,point Q,Vector v) {
	double t = cross(v,P-Q)/cross(u,v) ;
	P.x += u.x*t ;
	P.y += u.y*t ;
	return t ;
}

Vector rotate(Vector v,double t) {
	Vector u ;
	u.x = v.x*cos(t) - v.y*sin(t) ;
	u.y = v.y*cos(t) + v.x*sin(t) ;
	return u ;
}

double Cos(int a,int b) {
	return sqrt(a*a+b*b-2*a*b*cos(angle*PI/180.0)) ; // cos(angle)
}

double Area(double a,double b,double c) {
	double s = (a+b+c)/2 ;
	return sqrt(s*(s-a)*(s-b)*(s-c)) ;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
 
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{   
   float A = area (x1, y1, x2, y2, x3, y3);
 
   float A1 = area (x, y, x2, y2, x3, y3);
 
   float A2 = area (x1, y1, x, y, x3, y3);
 
   float A3 = area (x1, y1, x2, y2, x, y);
   
   return (A == A1 + A2 + A3);
}


float slope(pair <int, int > x,pair <int ,int > y) {
    float p = (float)(y.ss - x.ss) / (float)(y.ff - x.ff);
    return p;
}

bool equation(pii A,pii B,pii C) {
    float p = slope(A,B) * (C.ff - A.ff) - C.ss + A.ss;
    if(p > 0) return 1;
    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------

// volume of a pyramid with regular sides and edges

inline double vol(int n, double a)
{
	return n*a*a*a/12.0/tan(PI/n)*sqrt(1.0-0.25/sin(PI/n)/sin(PI/n));
}

----------------------------------------------------------------------------------------------------------------------------------

