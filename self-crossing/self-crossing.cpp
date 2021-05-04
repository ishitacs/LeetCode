 struct pt {
	int x, y;
};
int area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
 bool intersect_1 (int a, int b, int c, int d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect (pt a, pt b, pt c, pt d) {
	return intersect_1 (a.x, b.x, c.x, d.x)
		&& intersect_1 (a.y, b.y, c.y, d.y)
		&& area(a,b,c) * area(a,b,d) <= 0
		&& area(c,d,a) * area(c,d,b) <= 0;
}
class Solution {
public:
    bool isSelfCrossing(const vector<int>& x) {
	vector<pt> points;
	pt p({0,0});
	points.push_back(p);
	
	int offsetX = 0;
	int offsetY = 0;
	char wise = 0;
	for(int i = 0;i < x.size();i++)
	{
		pt p;
		p.x = offsetX +(i%2 ? (wise == 0 || wise ==3 ? 1 : -1)*x[i] : 0);
		p.y = offsetY + (i % 2 ? 0  : (wise == 0 || wise ==3 ? 1 : -1)*x[i]);
		offsetX = p.x;
		offsetY = p.y;
		points.push_back(p);
		wise++;
		if(wise == 4) wise = 0;
	}
	if(points.size() < 5) return false;
	for(int i = 0; i < points.size()-4;i++)
	{
		for(auto j = i+3 ;j < points.size()-1;j++)
		{
		if (intersect(points[i],points[i+1],points[j],points[j+1])) return true;	
		}
	}
       return false;
    }
};