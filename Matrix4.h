#pragma once

class Matrix4 {
//�����o�ϐ�
public:
	float mat[4][4];

//�����o�֐�
public:
	Matrix4();		//�R���X�g���N�^
	~Matrix4();		//�f�X�g���N�^

	Matrix4(			//�������w�肵�Ă̐���
		float mat00, float mat01, float mat02, float mat03,
		float mat10, float mat11, float mat12, float mat13,
		float mat20, float mat21, float mat22, float mat23,
		float mat30, float mat31, float mat32, float mat33
	);

	//������Z�q�I�[�o�[���[�h
	Matrix4& operator*=(const Matrix4& m2);
};