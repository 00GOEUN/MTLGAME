#include "BackGround.h"
#include "DoubleBuffer.h"

BackGround::BackGround()
{
}

BackGround::~BackGround()
{
	Release();
}

void BackGround::Initialize()
{
	TransInfo.Position = Vector3(70, 0); // 위치 초기화
	m_strKey = "Player";
}

int BackGround::Update()
{
	return 0;
}

void BackGround::Render()
{
	//  Stage 배경
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y, (char*)"     .      '         .   *              '            .            .       :", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 1, (char*)"   o           .            .            .            .        .   '         +       ' . ", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 2, (char*)"      ★   '            .   +         *            .      '           /      '                                 '   .", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 3, (char*)"       .        '      .        '  '       +     '            .      /      . o                                 +    .", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 4, (char*)"     .             '         o   . '        *      ☆          +    /     .      '", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 5, (char*)"          '.   *       +              , '               .       ' ★          +                                  '", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 6, (char*)"                      .      .             '                  +             '   .                                  .", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 7, (char*)"    o     .          '    .          +                 *             .  '                                         o  .", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 8, (char*)"     ,    '     *            '    .      /  '       .      '        .", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 9, (char*)"  '      .    '    .                 .  /          '  .                 ''      '.                             .   '", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 10, (char*)"     '        .         '     .       /     '  .            . '             '   . '", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 11, (char*)"     '           . o           '     *               ☆      .    '      .     '   .                             ★", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 12, (char*)"  ★     '         .       '               .      +             '    .", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 13, (char*)" *      ,   ;        ,              *       .    '   ☆         .    '          +          .     '    .  '", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 14, (char*)"                '     . ★          '    .          .      '            .   *.                '                     , ", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 15, (char*)"                '     .                   '   +            '            .   *        '   '.      '          .      '  ", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 16, (char*)"         *           '           .    '               /   .        ★            '              .   .", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 17, (char*)"		        '            .  '       ' .         /          '   .         '      .      '        .' ", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 18, (char*)" 	  '                '        '  .           /         ' +          .   o             '        .     '      ", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 19, (char*)"    '           .        '        .    '   /      ☆         ,       '   *            ,          '   '           ,   ' ", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 20, (char*)"     *        '   .    ☆      '      .   /          '            .   +                .     '        /    .   o   .", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 21, (char*)"                 +       '           .   /            '              ,    ,      '     .          ,  /        ,'", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 22, (char*)"  +          .  '          .   '       ★         ' .       '                 .              '      /  .            ' ", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 23, (char*)"       '              .                  '                 .          '.              ☆   '    .  *         '    '   ", 8);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 24, (char*)"           '        .            *          '                .              '   .                           .       ' ", 8);
	//DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 25, (char*)"                '     . ★                '   +            '            .   *        '   '.      '            .      '", 8);
	//DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 26, (char*)".'       *            .             '                           *                '                      ,        +", 8);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 70, (int)TransInfo.Position.y + 26, (char*)"_/↘._/↘.-'  .-' /~~↘/~↘ /~~↘/~↘_.--'_.--' ___/↘__.._._/~↘ `--./↘`--./↘`-/~↘_ `-/~↘_-/↘___/~↘/↘-.__/↘-.__", 2);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 2, (char*)"          __ _ __,", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 3, (char*)"      .--         --.", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 4, (char*)"    ./   ()      .-. *.", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 5, (char*)"   /   o    .   (   )  ↘ ", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 6, (char*)"  / .            '-'    ↘ ", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 7, (char*)" | ()    .  O         .  |", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 8, (char*)"|    o           ()       |", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 9, (char*)"|       .--.          O   |", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 10, (char*)" | .   |    |            |", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 11, (char*)"  *    `.__.'    o   .  / ", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 12, (char*)"   ↘                   /", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 13, (char*)"   `↘  o    ()      /'", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 14, (char*)"       `--___ _ ___--'", 6);
}

void BackGround::Release()
{
}
