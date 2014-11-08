/*************************************************************************** 
 *   Copyright (C) 2014 by Maxim Fetisov                                   * 
 *   blizzard005 at gmail dot com                                          * 
 **************************************************************************/
 
        //Compute the dot product AB.AC
        //private double DotProduct(double[] pointA, double[] pointB, double[] pointC)
        //{
        //    double[] AB = new double[2];
        //    double[] BC = new double[2];
        //    AB[0] = pointB[0] - pointA[0];
        //    AB[1] = pointB[1] - pointB[1];
        //    BC[0] = pointC[0] - pointB[0];
        //    BC[1] = pointC[1] - pointB[1];
        //    double dot = AB[0] * BC[0] + AB[1] * BC[1];

        //    return dot;
        //}



        private double DotProduct(double[] v, double[] w)
        {
            double dot;
            return dot = v[0] * w[0] + v[1] * w[1];
        }


        private double CrossProduct(double[] v, double[] w)
        {
            double cross = v[0] * w[1] + v[1] * w[0];
            return cross;
        }

        private double DotProduct3D(double[] v, double[] w)
        {
            double dot;
            return dot = v[0] * w[0] + v[1] * w[1] + v[2] * w[2];
        }


        private double CrossProduct3D(double[] v, double[] w)
        {
            double cross = v[0] * w[1] + v[1] * w[0]
                + v[2] * w[0] + v[0] * w[2] + v[1] * w[2] + v[2] * w[1];
            return cross;
        }

        //Compute the cross product ABxAC
        //private double CrossProduct(double[] pointA, double[] pointB, double[] pointC)
        //{
        //    double[] AB = new double[2];
        //    double[] AC = new double[2];
        //    AB[0] = pointB[0] - pointA[0];
        //    AB[1] = pointB[1] - pointA[1];
        //    AC[0] = pointC[0] - pointA[0];
        //    AC[1] = pointC[1] - pointA[1];    
        //    double cross = AB[0] * AC[1] + AB[1] * AC[0];

        //    return cross;
        //}




        //compute the distance from A to B
        double Distance(double[] PointA, double[] PointB)
        {
            double d1 = PointA[0] - PointB[0];
            double d2 = PointA[1] - PointB[1];

            return Math.Sqrt(d1 * d1 + d2 * d2);
        }

        double Distance3D(double[] PointA, double[] PointB)
        {
            double d1 = PointA[0] - PointB[0];
            double d2 = PointA[1] - PointB[1];
            double d3 = PointA[2] - PointB[2];

            return Math.Sqrt(d1 * d1 + d2 * d2 + d3 * d3);
        }

        double LineToLineDistance3D(double[] pointA, double[] pointB, double[] pointC, double[] pointD)
        {
            double l1 = pointB[0] - pointA[0];
            double m1 = pointB[1] - pointA[1];
            double n1 = pointB[2] - pointA[2];
            double[] pointV = new double[3] { l1, m1, n1 };// directing vector of 1st line
            double l2 = pointD[0] - pointC[0];
            double m2 = pointD[1] - pointC[1];
            double n2 = pointD[2] - pointC[2];
            double[] pointW = new double[3] { l2, m2, n2 };// directing vector of 2nd line
            double[] diff = new double[3] { pointC[0] - pointA[0], pointC[1] - pointA[1], pointC[2] - pointA[2] };

            if (l1 != l2 && m1 != m2 && n1 != n2)
            {

                double[] det = new double[3] { m1 * n2 - n1 * m2, n1 * l2 - l1 * n2, l1 * m2 - m1 * l2 };

                double numerator = Math.Abs(DotProduct3D(diff, det));
                // MessageBox.Show("numerator="+numerator);           
                double denominator = Math.Sqrt(DotProduct3D(det, det));
                //MessageBox.Show("denominator="+denominator);
                double d = numerator / denominator;
                return d;
            }
            else // if lines are parallel
            {
                double[] det2 = new double[3] { m1 * diff[2] - n1 * diff[1], n1 * diff[0] - l1 * diff[2], l1 * diff[1] - m1 * diff[0] };
                double numerator = Math.Sqrt(Math.Abs(DotProduct3D(det2, det2)));
                double denominator = Math.Sqrt(Math.Abs(DotProduct3D(pointV, pointV)));
                double d2 = numerator / denominator;
                return d2;
            }
        }

        double LineToPointDistance3D(double[] pointA, double[] pointB, double[] pointC)
          // ,bool isSegment)
        {
            double d1 = pointB[0] - pointA[0];
            double d2 = pointB[1] - pointA[1];
            double d3 = pointB[2] - pointA[2];
            double[] pointV = new double[3] { d1, d2, d3 };

            double d4 = pointC[0] - pointA[0];
            double d5 = pointC[1] - pointA[1];
            double d6 = pointC[2] - pointA[2];
            double[] pointW = new double[3] { d4, d5, d6 };

            double c1 = DotProduct3D(pointV, pointW);
            double c2 = DotProduct3D(pointV, pointV);
            double b = c1 / c2;
            double[] pointI = new double[3]{pointA[0]+b*pointV[0],
                pointA[1]+b*pointV[1],pointA[2]+b*pointV[2]};
            return Distance3D(pointC, pointI);

        }
        //Compute the distance from AB to C
        //if isSegment is true , AB is segment , not a line



        double LineToPointDistance2D(double[] pointA, double[] pointB, double[] pointC)
          //  ,bool isSegment)
        {
            double d1 = pointB[0] - pointA[0];
            double d2 = pointB[1] - pointA[1];
            double[] pointV = new double[2] { d1, d2 };

            double d3 = pointC[0] - pointA[0];
            double d4 = pointC[1] - pointA[1];
            double[] pointW = new double[2] { d3, d4 };

            double c1 = DotProduct(pointV, pointW);
            double c2 = DotProduct(pointV, pointV);
            double b = c1 / c2;
            double[] pointI = new double[2] { pointA[0] + b * pointV[0], pointA[1] + b * pointV[1] };
            return Distance(pointC, pointI);

            //double dist = CrossProduct(pointA, pointB, pointC)/Distance(pointA,pointB);
            //double dist = Distance(pointA,pointB);

            //if (isSegment)
            //{
            //    double dot1 = DotProduct(pointA,pointB,pointC);
            //    if (dot1 > 0)
            //        return Distance(pointB, pointC);

            //    double dot2 = DotProduct(pointB, pointA, pointC);
            //    if (dot2 > 0)
            //        return Distance(pointA, pointC);
            //}
            //return Math.Abs(dist);

        }
        public Paint()
        {
            InitializeComponent();
            //enum_example();

            //pointf[0].X = 5F;
            //pointf[0].Y = 3F;
            //pointf[1].X = 11;
            //pointf[1].Y = 6;

            pointf[0].X = 5F;
            pointf[0].Y = 5F;
            pointf[1].X = 8;
            pointf[1].Y = 11;


            //pointf[2].X = 5;
            //pointf[2].Y = 5;
            //pointf[3].X = 8;
            //pointf[3].Y = 11;

            pointf[2].X = 2;
            pointf[2].Y = 2;
            pointf[3].X = 7;
            pointf[3].Y = 2;




            pointf[4].X = 456;
            pointf[4].Y = 623;
            pointf[5].X = 3;
            pointf[5].Y = 9;
            pointf[6].X = 3;
            pointf[6].Y = 5;
            pointf[7].X = 4;
            pointf[7].Y = 6;
            pointf[8].X = 0;
            pointf[8].Y = 4;
            pointf[9].X = 5;
            pointf[9].Y = 4;
            //pointf[10].X = 3;
            //pointf[10].Y = 5;
            //pointf[10].X = 3;
            //pointf[10].Y = 5;
            //PointF p1 = new PointF();       
            //intersect.X = 0;
            //intersect.Y = 0;
            
            //LineIntersectsLine(pointf[0], pointf[1], pointf[2], pointf[3], out intersect);



            double[] pA = new double[2] { 0, 0.625 };
            double[] pB = new double[2] { 1, -0.125 };
            double[] pC = new double[2] { 2, 5 };

            double[] pA3 = new double[3] { 0, 0, 50 };
            double[] pB3 = new double[3] { 0, 0, -50 };
            double[] pC3 = new double[3] { 10, 50, 10 };

            double[] A = new double[3] { 2, 1, -1 };
            double[] B = new double[3] { 4, 5, -2 };
            double[] C = new double[3] { -31, 6, 3 };
            double[] D = new double[3] { -28, 8, 9 };

            double[] A2 = new double[3] { 2, 3, 0 };
            double[] B2 = new double[3] { 4, 5, 1 };
            double[] C2 = new double[3] { 5, 4, 1 };
            double[] D2 = new double[3] { 7, 6, 2 };


            // double distance;
            //distance = ;
            MessageBox.Show("LineToPointDistance2D: " + LineToPointDistance2D(pA, pB, pC));
            MessageBox.Show("LineToPointDistance3D: " + LineToPointDistance3D(pA3, pB3, pC3));
            MessageBox.Show("LineToLIneDistance3D: " + LineToLineDistance3D(A, B, C, D));
            MessageBox.Show("Distance2: " + LineToLineDistance3D(A2, B2, C2, D2));
        }
