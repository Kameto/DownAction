/*
学籍番号：j17086
名前：亀田朋来
*/

#pragma once

// マクロ定義 //
#define DEL_OBJ(x) if((x) != nullptr) { delete (x); (x) = nullptr; }

// 数値定義 //
#define DEFAULT_SPD		 8.0
#define DEFAULT_GRV		 6.0
#define WALL_WIDTH		 256
#define STARTPOINT		 96
#define STAGE_HIEGHT	 320
#define STAGE_WIDTH		 12
#define WIND_HEIGHT		 1080
#define WIND_WIDTH		 1920
#define ENEGY_MAX		 512
#define ENEGY_UP		 32
#define TRANS_TIME		 640
#define PI				 3.1415926535897932384626433832795f