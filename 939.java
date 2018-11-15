class Solution {
    public int minAreaRect(int[][] points) {
        Set<Point> set = new HashSet<Point>();
        for (int i = 0; i < points.length; ++i) {
            set.add(new Point(points[i][0], points[i][1]));
        }
   //     System.out.println(set.size());
        final int INF = 1000000000;
        int minx = INF;
        for (int i = 0; i < points.length; ++i) {
            for (int j = i + 1; j < points.length; ++j) {
                if (points[i][0] == points[j][0])   continue;
                if (points[i][1] == points[j][1])   continue;
                Point left = new Point(points[i][0], points[j][1]);
                Point right = new Point(points[j][0], points[i][1]);
                 // System.out.println(left.x + " " + left.y);
                // System.out.println(right.x + " " + right.y);
                if (set.contains(left) && set.contains(right)) {
     //               System.out.println("1111");
                    minx = Math.min(Math.abs(points[i][0] - points[j][0]) * Math.abs(points[i][1] - points[j][1]), minx);
                }
            }
        }
        if (minx == INF)    minx = 0;
        return minx;
    }
}
class Point {
    int x, y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public boolean equals(Object other) {
      //  System.out.println(this.toString());
        if (!(other instanceof Point)) {
            return false;
        }
       // System.out.println(((Point)other).toString());
        if (other == this) {
            return true;
        } 
        if (this.x == ((Point)other).x && this.y == ((Point)other).y) {
            return true;
        }
        return false;
    }
    public String toString() {
        return x + " " + y;
    }
    public int hashCode() {
        String hash = x + "_" + y;
        return hash.hashCode();
    }
}