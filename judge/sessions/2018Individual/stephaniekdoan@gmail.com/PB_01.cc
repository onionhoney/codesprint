{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf400
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;\red100\green56\blue32;\red255\green255\blue255;\red196\green26\blue22;
\red170\green13\blue145;\red0\green0\blue0;\red92\green38\blue153;\red28\green0\blue207;\red46\green13\blue110;
}
{\*\expandedcolortbl;;\csgenericrgb\c39100\c22000\c12500;\csgray\c100000;\csgenericrgb\c77000\c10200\c8600;
\csgenericrgb\c66500\c5200\c56900;\csgenericrgb\c0\c0\c0;\csgenericrgb\c35900\c14900\c60100;\csgenericrgb\c11000\c0\c81000;\csgenericrgb\c18100\c5200\c43100;
}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab543
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f0\fs22 \cf2 \cb3 #include \cf4 <iostream>
\f1\fs24 \cf0 \

\f0\fs22 \cf2 #include \cf4 <vector>
\f1\fs24 \cf0 \
\

\f0\fs22 \cf5 int\cf6  main()
\f1\fs24 \cf0 \

\f0\fs22 \cf6 \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \cf5 int\cf6  testCases;
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \cf7 std\cf6 ::\cf7 vector\cf6 <\cf5 int\cf6 > results;
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \cf7 std\cf6 ::\cf7 cin\cf6  >> testCases;
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \cf5 for\cf6  (\cf5 int\cf6  x=\cf8 0\cf6 ; x<testCases; x++)
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf5 for\cf6  (\cf5 int\cf6  rounds=\cf8 0\cf6 ; rounds<\cf8 3\cf6 ; rounds++)
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6             \cf5 for\cf6  (\cf5 int\cf6  i=\cf8 0\cf6 ; i<\cf8 100\cf6 ; i++)
\f1\fs24 \cf0 \

\f0\fs22 \cf6             \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6                 \cf5 int\cf6  number;
\f1\fs24 \cf0 \

\f0\fs22 \cf6                 \cf7 std\cf6 ::\cf7 cin\cf6  >> number;
\f1\fs24 \cf0 \

\f0\fs22 \cf6                 \cf5 if\cf6  (number == \cf8 1\cf6 )
\f1\fs24 \cf0 \

\f0\fs22 \cf6                 \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6                     results.\cf9 push_back\cf6 (i);
\f1\fs24 \cf0 \

\f0\fs22 \cf6                 \}
\f1\fs24 \cf0 \

\f0\fs22 \cf6             \}
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \}
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \}
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \cf5 for\cf6  (\cf5 int\cf6  i=\cf8 0\cf6 ; i<results.\cf9 size\cf6 (); i++)
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \{
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf7 std\cf6 ::\cf7 cout\cf6  << results[\cf9 i\cf6 ] << \cf4 " "\cf6 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf6         \cf5 if\cf6  (i+\cf8 1\cf6  % \cf8 3\cf6  == \cf8 0\cf6 )
\f1\fs24 \cf0 \

\f0\fs22 \cf6             \cf7 std\cf6 ::\cf7 cout\cf6  << \cf7 std\cf6 ::\cf9 endl\cf6 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf6     \}
\f1\fs24 \cf0 \

\f0\fs22 \cf6 \}
\f1\fs24 \cf0 \
}