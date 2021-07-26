#pragma once

// 키 입력
const ULONG KEYID_LEFT	= 0x00000001; // 좌
const ULONG KEYID_RIGHT = 0x00000002; // 우
const ULONG KEYID_SPACE	= 0x00000004; // 점프

const ULONG KEYID_AKEY	= 0x00000008; // 공격
const ULONG KEYID_SKEY	= 0x00000010; // 스킬

const ULONG KEYID_UP	= 0x00000020; // 위
const ULONG KEYID_DOWN	= 0x00000040; // 아래
const ULONG KEYID_ENTER	= 0x00000080; // 선택

// 콘솔 창 크기
const int CONSOL_MAX_WIDTH	= 120; // 넓이
const int CONSOL_MAX_HEIGHT = 30; // 높이


// 뭔지 모르겠음
//const int ENEMY_CNT_MAX = 64;
#define GRAVITY_ACCELERATION 0.98f
// 원주율
#define PI 3.141592f

const int DIR_RIGHT = 0;
const int DIR_LEFT = 1;
