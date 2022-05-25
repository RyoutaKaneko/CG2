#pragma once

class Matrix4 {
//メンバ変数
public:
	float mat[4][4];

//メンバ関数
public:
	Matrix4();		//コンストラクタ
	~Matrix4();		//デストラクタ

	Matrix4(			//成分を指定しての生成
		float mat00, float mat01, float mat02, float mat03,
		float mat10, float mat11, float mat12, float mat13,
		float mat20, float mat21, float mat22, float mat23,
		float mat30, float mat31, float mat32, float mat33
	);

	//代入演算子オーバーロード
	Matrix4& operator*=(const Matrix4& m2);
};