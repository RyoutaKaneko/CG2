#include "Matrix4.h"

//コンストラクタ
Matrix4::Matrix4() {};
//デストラクタ
Matrix4::~Matrix4() {};

//引数付きの宣言
Matrix4::Matrix4(
	float mat00, float mat01, float mat02, float mat03,
	float mat10, float mat11, float mat12, float mat13,
	float mat20, float mat21, float mat22, float mat23,
	float mat30, float mat31, float mat32, float mat33
) {
	mat[0][0] = mat00; mat[0][1] = mat01; mat[0][2] = mat02; mat[0][3] = mat03;
	mat[1][0] = mat10; mat[1][1] = mat11; mat[1][2] = mat12; mat[1][3] = mat13;
	mat[2][0] = mat20; mat[2][1] = mat21; mat[2][2] = mat22; mat[2][3] = mat23;
	mat[3][0] = mat30; mat[3][1] = mat31; mat[3][2] = mat32; mat[3][3] = mat33;
};

//代入演算子オーバーロード
Matrix4& Matrix4::operator*=(const Matrix4& m2) {
	Matrix4 ans;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				ans.mat[i][j] += mat[i][k] * m2.mat[k][j];

			}
		}
	}

	return ans;
}

Matrix4 Matrix4::operator*(const Matrix4& m2) {
	Matrix4 ans;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				ans.mat[i][j] += mat[i][k] * m2.mat[k][j];

			}
		}
	}

	return ans;
}