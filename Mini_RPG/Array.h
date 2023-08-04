#pragma once
#include <iostream>

//Array 클래스
template <typename T>
class CArray
{
public:
	//생성자
	CArray()
	{
		//초기 설정 
		mCapacity = 4; //용량 4
		mCount = 0;    //개수 0 

		mData = new T[mCapacity]; //용량에 맞는 데이터베열 동적할당
	}
	//소멸자
	~CArray()
	{
		delete[] mData; //데이터 배열 delete
	}

private:
	//T	mData[50];  //배열 용량을 고정할 수 있지만
	T* mData;		//바꾸기 위함
	int mCapacity;	//배열이 총 몇개인지를 저장
	int mCount;		//실제 추가된 데이터 수

public:
	//데이터 추가
	void push_back(const T& data)
	{
		//배열이 꽉 찼는지 검사한다. 
		if (mCapacity == mCount)
		{
			//용량 2배로 늘려줌
			mCapacity *= 2;

			//늘어난 공간을 할당한다. 
			T* Array = new T[mCapacity];

			//원래의 배열에 있던 데이터를 늘어난 공간에 복사한다. 
			//Dest : 복사할 위치
			//Sourse : 복사대상 위치
			//Size : 복사할 바이트 수
			//Sourse에 지정된 메모리 주소로부터 Size에  지정된 바이트 수만큼을 
			//Dest에 지정된 메모리에 Size에 지정된 바이트 수만큼 복사한다. 
			//sizeof(T) : 배열 1개의 크기
			memcpy(Array, mData, sizeof(T) * mCount);

			//원본 배열을 제거한다. 
			delete[] mData;

			//공간이 늘어나서 재할당된 배열을 실제 배열로 사용할 수 있게 그 주소를 포인터에 넣어준다.
			mData = Array;
		}

		mData[mCount] = data; //마지막에 데이터 추가
		++mCount;			  //개수 +1
	}

	//마지막 데이터 제거
	void pop_back()
	{
		//개수가 0이면 리턴
		if (mCount == 0)
			return;

		--mCount; //아니면 데이터 개수 줄여줌
	}

	//중간 데이터 지우기
	void Remove(int Index)
	{
		//index 예외 처리 
		if (Index < 0 || Index >= mCount)
			return;

		//지울 데이터 기준 뒤에 있는 데이터를 하나씩 앞으로
		for (int i = Index; i < mCount - 1; ++i)
		{
			mData[i] = mData[i + 1];
		}

		--mCount; //개수 -1
	}

	/*
	함수 뒤에 const를 붙이게 되면 함수에서는 멤버변수의 값을 변경할 수 없다.
	만약 이 클래스를 이용해서 생성된 객체가 const 변수에 저장된다면 함수 뒤에 const를 붙여준 함수만 호출이 가능하다.
	*/
	//저장 개수 호출
	int size() const
	{
		return mCount;
	}
	//용량 호출
	int capacity() const
	{
		return mCapacity;
	}
	//비어있는지 여부, 비어있으면 =1(true)
	bool empty() const
	{
		return mCount == 0;
	}
	//인덱스에 해당하는 데이터 호출
	T& Get(int Index = 0) const
	{
		return mData[Index];
	}
	//operator오버로딩으로 데이터 호출
	T& operator [] (int Index) const
	{
		return mData[Index];
	}
};