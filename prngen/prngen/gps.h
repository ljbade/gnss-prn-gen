// Table of GPS PRN C/A code generator settings
unsigned short int gps_prn[210][3] = 
{
	// Lower PRNs (1 - 37)
	// From IS-GPS-200C, Table 3-Ia
	// PRN number, G2 delay, initial G2 setting, first 10 chips
	//                    always  '11 1111 1111'
	/*          1, */     5,              01777,          01440,
	/*          2, */     6,              01777,          01620,
	/*          3, */     7,              01777,          01710,
	/*          4, */     8,              01777,          01744,
	/*          5, */    17,              01777,          01133,
	/*          6, */    18,              01777,          01455,
	/*          7, */   139,              01777,          01131,
	/*          8, */   140,              01777,          01454,
	/*          9, */   141,              01777,          01626,
	/*         10, */   251,              01777,          01504,
	/*         11, */   252,              01777,          01642,
	/*         12, */   254,              01777,          01750,
	/*         13, */   255,              01777,          01764,
	/*         14, */   256,              01777,          01772,
	/*         15, */   257,              01777,          01775,
	/*         16, */   258,              01777,          01776,
	/*         17, */   469,              01777,          01156,
	/*         18, */   470,              01777,          01467,
	/*         19, */   471,              01777,          01633,

	/*         20, */   472,              01777,          01715,
	/*         21, */   473,              01777,          01746,
	/*         22, */   474,              01777,          01763,
	/*         23, */   509,              01777,          01063,
	/*         24, */   512,              01777,          01706,
	/*         25, */   513,              01777,          01743,
	/*         26, */   514,              01777,          01761,
	/*         27, */   515,              01777,          01770,
	/*         28, */   516,              01777,          01774,
	/*         29, */   859,              01777,          01127,
	/*         30, */   860,              01777,          01453,
	/*         31, */   861,              01777,          01625,
	/*         32, */   862,              01777,          01712,
	/*         33, */   863,              01777,          01745,
	/*         34, */   950,              01777,          01713,
	/*         35, */   947,              01777,          01134,
	/*         36, */   948,              01777,          01456,
	/*         37, */   950,              01777,          01713,

	// Upper PRNs (38 - 63)
	// From IS-GPS-200C, Table 3-Ib
	// PRN number, G2 delay, initial G2 setting, first 10 chips
	/*         38, */    67,              00017,          01760,
	/*         39, */   103,              00541,          01236,
	/*         40, */    91,              01714,          00063,
	/*         41, */    19,              01151,          00626,
	/*         42, */   679,              01651,          00126,
	/*         43, */   225,              00103,          01674,
	/*         44, */   625,              00543,          01234,
	/*         45, */   946,              01506,          00271,
	/*         46, */   638,              01065,          00712,
	/*         47, */   161,              01564,          00213,
	/*         48, */  1001,              01365,          00412,
	/*         49, */   554,              01541,          00236,
	/*         50, */   280,              01327,          00450,
	/*         51, */   710,              01716,          00061,
	/*         52, */   709,              01635,          00142,
	/*         53, */   775,              01002,          00775,
	/*         54, */   864,              01015,          00762,
	/*         55, */   558,              01666,          00111,
	/*         56, */   220,              00177,          01600,
	/*         57, */   397,              01353,          00424,
	/*         58, */    55,              00426,          01351,
	/*         59, */   898,              00227,          01550,
	/*         60, */   759,              00506,          01271,
	/*         61, */   367,              00336,          01441,
	/*         62, */   299,              01333,          00444,
	/*         63, */  1018,              01745,          00032,
		
	// Additional PRNs (64 - 210)
	// From IS-GPS-200C, Table 6-I
	// PRN number, G2 delay, initial G2 setting, first 10 chips
	/*         64, */   729,              00254,          01523,
	/*         65, */   695,              01602,          00175,
	/*         66, */   780,              01160,          00617,
	/*         67, */   801,              01114,          00663,
	/*         68, */   788,              01324,          00435,
	/*         69, */   732,              00025,          01752,
	/*         70, */    34,              01523,          00254,
	/*         71, */   320,              01046,          00731,
	/*         72, */   327,              00404,          01373,
	/*         73, */   389,              01445,          00332,
	/*         74, */   407,              01054,          00723,
	/*         75, */   525,              00072,          01705,
	/*         76, */   405,              00262,          01515,
	/*         77, */   221,              00077,          01700,
	/*         78, */   761,              00521,          01256,
	/*         79, */   260,              01400,          00377,
	/*         80, */   326,              01010,          00767,
	/*         81, */   955,              01441,          00336,
	/*         82, */   653,              00365,          01412,
	/*         83, */   699,              00270,          01507,
	/*         84, */   422,              00263,          01514,
	/*         85, */   188,              00613,          01164,
	/*         86, */   438,              00277,          01500,
	/*         87, */   959,              01562,          00215,
	/*         88, */   539,              01674,          00103,
	/*         89, */   879,              01113,          00664,
	/*         90, */   677,              01245,          00532,
	/*         91, */   586,              00606,          01171,
	/*         92, */   153,              00136,          01641,
	/*         93, */   792,              00256,          01521,
	/*         94, */   814,              01550,          00227,
	/*         95, */   446,              01234,          00543,

	/*         96, */   264,              00260,          01517,
	/*         97, */  1015,              01455,          00322,
	/*         98, */   278,              01535,          00242,
	/*         99, */   536,              00746,          01031,
	/*        100, */   819,              01033,          00744,
	/*        101, */   156,              01213,          00564,
	/*        102, */   957,              00710,          01067,
	/*        103, */   159,              00721,          01056,
	/*        104, */   712,              01763,          00014,
	/*        105, */   885,              01751,          00026,
	/*        106, */   461,              00435,          01342,
	/*        107, */   248,              00735,          01042,
	/*        108, */   713,              00771,          01006,
	/*        109, */   126,              00140,          01637,
	/*        110, */   807,              00111,          01666,
	/*        111, */   279,              00656,          01121,
	/*        112, */   122,              01016,          00761,
	/*        113, */   197,              00462,          01315,
	/*        114, */   693,              01011,          00766,
	/*        115, */   632,              00552,          01225,
	/*        116, */   771,              00045,          01732,
	/*        117, */   467,              01104,          00673,
	/*        118, */   647,              00557,          01220,
	/*        119, */   203,              00364,          01413,
	/*        120, */   145,              01106,          00671,
	/*        121, */   175,              01241,          00536,
	/*        122, */    52,              00267,          01510,
	/*        123, */    21,              00232,          01545,
	/*        124, */   237,              01617,          00160,
	/*        125, */   235,              01076,          00701,

	/*        126, */   886,              01764,          00013,
	/*        127, */   657,              00717,          01060,
	/*        128, */   634,              01532,          00245,
	/*        129, */   762,              01250,          00527,
	/*        130, */   355,              00341,          01436,
	/*        131, */  1012,              00551,          01226,
	/*        132, */   176,              00520,          01257,
	/*        133, */   603,              01731,          00046,
	/*        134, */   130,              00706,          01071,
	/*        135, */   359,              01216,          00561,
	/*        136, */   595,              00740,          01037,
	/*        137, */    68,              01007,          00770,
	/*        138, */   386,              00450,          01327,
	/*        139, */   797,              00305,          01472,
	/*        140, */   456,              01653,          00124,
	/*        141, */   499,              01411,          00366,
	/*        142, */   883,              01644,          00133,
	/*        143, */   307,              01312,          00465,
	/*        144, */   127,              01060,          00717,
	/*        145, */   211,              01560,          00217,
	/*        146, */   121,              00035,          01742,
	/*        147, */   118,              00355,          01422,
	/*        148, */   163,              00335,          01442,
	/*        149, */   628,              01254,          00523,
	/*        150, */   853,              01041,          00736,
	/*        151, */   484,              00142,          01635,
	/*        152, */   289,              01641,          00136,
	/*        153, */   811,              01504,          00273,
	/*        154, */   202,              00751,          01026,
	/*        155, */  1021,              01774,          00003,
		
	/*        156, */   463,              00107,          01670,
	/*        157, */   568,              01153,          00624,
	/*        158, */   904,              01542,          00235,
	/*        159, */   670,              01223,          00554,
	/*        160, */   230,              01702,          00075,
	/*        161, */   911,              00436,          01341,
	/*        162, */   684,              01735,          00042,
	/*        163, */   309,              01662,          00115,
	/*        164, */   644,              01570,          00207,
	/*        165, */   932,              01573,          00204,
	/*        166, */    12,              00201,          01576,
	/*        167, */   314,              00635,          01142,
	/*        168, */   891,              01737,          00040,
	/*        169, */   212,              01670,          00107,
	/*        170, */   185,              00134,          01643,
	/*        171, */   675,              01224,          00553,
	/*        172, */   503,              01460,          00317,
	/*        173, */   150,              01362,          00415,
	/*        174, */   395,              01654,          00123,
	/*        175, */   345,              00510,          01267,
	/*        176, */   846,              00242,          01535,
	/*        177, */   798,              01142,          00635,
	/*        178, */   992,              01017,          00760,
	/*        179, */   357,              01070,          00707,
	/*        180, */   995,              00501,          01276,
	/*        181, */   877,              00455,          01322,
	/*        182, */   112,              01566,          00211,
	/*        183, */   144,              00215,          01562,
	/*        184, */   476,              01003,          00774,
	/*        185, */   193,              01454,          00323,
		
	/*        186, */   109,              01665,          00112,
	/*        187, */   445,              00471,          01306,
	/*        188, */   291,              01750,          00027,
	/*        189, */    87,              00307,          01470,
	/*        190, */   399,              00272,          01505,
	/*        191, */   292,              00764,          01013,
	/*        192, */   901,              01422,          00355,
	/*        193, */   339,              01050,          00727,
	/*        194, */   208,              01607,          00170,
	/*        195, */   711,              01747,          00030,
	/*        196, */   189,              01305,          00472,
	/*        197, */   263,              00540,          01237,
	/*        198, */   537,              01363,          00414,
	/*        199, */   663,              00727,          01050,
	/*        200, */   942,              00147,          01630,
	/*        201, */   173,              01206,          00571,
	/*        202, */   900,              01045,          00732,
	/*        203, */    30,              00476,          01301,
	/*        204, */   500,              00604,          01173,
	/*        205, */   935,              01757,          00020,
	/*        206, */   556,              01330,          00447,
	/*        207, */   373,              00663,          01114,
	/*        208, */    85,              01436,          00341,
	/*        209, */   652,              00753,          01024,
	/*        210, */   310,              00731,          01046
};