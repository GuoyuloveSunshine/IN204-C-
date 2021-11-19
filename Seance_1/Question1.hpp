#ifndef question1hpp
#define question1hpp
class Point{
    private:
        int m_x;
        int m_y;
    public:
        Point(int x, int y): m_x(x),m_y(y){};
        Point(const Point & another_point):m_x(another_point.m_x),m_y(another_point.m_y){};
        int get_x(){ return m_x; }
        int get_y(){ return m_y; }
};

class Segment{
    private:
        Point m_start;
        Point m_end;
    public:
        Segment(const Point & point_start,const Point & point_end):m_start(point1),m_end(point2){};
        Segment(int start_x, int start_y, int end_x, int end_y): m_start(start_x,start_y),m_end(end_x,end_y){};
        Segment(const Segment& anotherSegment): m_start(anotherSegment.m_start), m_end(anotherSegment.m_end){};
        bool is_point_in_segment( Point pointnew){
            if (m_start.get_x() == m_end.get_x()){
                if (pointnew.get_x()!= m_start.get_x()){ return false;}
                else if(m_start.getY() <= m_end.getY()){
                    if(aPoint.getY() < m_start.getY() || aPoint.getY() > m_end.getY()) {return false;}
                }
                else{
                    if(aPoint.getY() > m_start.getY() || aPoint.getY() < m_end.getY()) {return false;}
                }
                return true;
            }
            else if((pointnew.get_y()-m_start.get_y())/(pointnew.get_x()-m_start.get_x())==(m_end.get_y()-pointnew.get_y())/(m_end.get_x()-pointnew.get_x()))
            { return true;}
            else{ return false;}
        }
};

#endif
