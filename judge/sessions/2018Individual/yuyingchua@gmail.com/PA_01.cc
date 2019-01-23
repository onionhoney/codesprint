{\rtf1\ansi\ansicpg1252\cocoartf1504\cocoasubrtf830
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red255\green255\blue255;\red196\green26\blue22;
\red170\green13\blue145;\red0\green0\blue0;\red92\green38\blue153;\red28\green0\blue207;\red46\green13\blue110;
}
{\*\expandedcolortbl;;\csgenericrgb\c39100\c22000\c12500;\csgray\c100000;\csgenericrgb\c77000\c10200\c8600;
\csgenericrgb\c66500\c5200\c56900;\csgenericrgb\c0\c0\c0;\csgenericrgb\c35900\c14900\c60100;\csgenericrgb\c11000\c0\c81000;\csgenericrgb\c18100\c5200\c43100;
}
\margl1440\margr1440\vieww26280\viewh15700\viewkind0
\deftab543
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f0\fs22 \cf2 \cb3 #include \cf4 <iostream>
\f1\fs24 \cf0 \cb3 \

\f0\fs22 \cf2 \cb3 #include \cf4 <vector>
\f1\fs24 \cf0 \cb3 \
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f0\fs22 \cf5 using\cf6  \cf5 namespace\cf6  \cf7 std\cf6 ;
\f1\fs24 \cf0 \
\

\f0\fs22 \cf5 int\cf6  main() \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \cf5 int\cf6  testcases;
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \cf7 cin\cf6  >> testcases;
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \cf7 vector\cf6 <\cf5 int\cf6 > maxStudents;
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \cf5 for\cf6  (\cf5 int\cf6  i = \cf8 1\cf6 ; i <= testcases; i++)
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf5 int\cf6  smallbergJump;
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf7 cin\cf6  >> smallbergJump;
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf5 int\cf6  CS31options;
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf5 int\cf6  CS32options;
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf7 cin\cf6  >> CS31options;
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf7 cin\cf6  >> CS32options;
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf7 vector\cf6 <\cf5 int\cf6 > ClassSize31;
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf7 vector\cf6 <\cf5 int\cf6 > ClassSize32;
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf5 for\cf6  (\cf5 int\cf6  j = \cf8 0\cf6 ; j < CS31options; j++)
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6             \cf5 int\cf6  cs31classsize;
\f1\fs24 \cf0 \

\f0\fs22 \cf6             \cf7 cin\cf6  >> cs31classsize;
\f1\fs24 \cf0 \

\f0\fs22 \cf6             ClassSize31.\cf9 push_back\cf6 (cs31classsize);
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \}
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf5 for\cf6  (\cf5 int\cf6  k = \cf8 0\cf6 ; k < CS32options; k++)
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6             \cf5 int\cf6  cs32classsize;
\f1\fs24 \cf0 \

\f0\fs22 \cf6             \cf7 cin\cf6  >> cs32classsize;
\f1\fs24 \cf0 \

\f0\fs22 \cf6             ClassSize32.\cf9 push_back\cf6 (cs32classsize);
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \}
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf5 int\cf6  maxS = \cf8 0\cf6 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf5 for\cf6  (\cf5 int\cf6  j = \cf8 0\cf6 ; j < CS31options; j++)
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6             \cf5 for\cf6  (\cf5 int\cf6  k = \cf8 0\cf6 ; k < CS32options; k++)
\f1\fs24 \cf0 \

\f0\fs22 \cf6             \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6                 \cf5 int\cf6  studentsTaught = ClassSize31[\cf9 j\cf6 ] + ClassSize32[\cf9 k\cf6 ];
\f1\fs24 \cf0 \

\f0\fs22 \cf6                 \cf5 if\cf6 (studentsTaught <= smallbergJump && studentsTaught > maxS)
\f1\fs24 \cf0 \

\f0\fs22 \cf6                 maxS = studentsTaught;
\f1\fs24 \cf0 \

\f0\fs22 \cf6             \}
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \}
\f1\fs24 \cf0 \

\f0\fs22 \cf6         maxStudents.\cf9 push_back\cf6 (maxS);
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \}
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \cf5 for\cf6  (\cf5 int\cf6  i = \cf8 0\cf6 ; i < maxStudents.\cf9 size\cf6 (); i++)
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf7 cout\cf6  << maxStudents[\cf9 i\cf6 ] << \cf9 endl\cf6 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf6 \}
\f1\fs24 \cf0 \
}