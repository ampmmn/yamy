Yet Another Mado tsukai no Yuutsu(YAMY) ver.0.02

1. �T�v

Windows�p�ėp�L�[�o�C���f�B���O�ύX�\�t�g�u���g���̗J�T(�Ȍ�mayu�ƕ\�L)�v
(http://mayu.sourceforge.net/)�̃L�[���͒u�����h���C�o�x�[�X���烆�[�U
���[�h�t�b�N�x�[�X�ɕύX�����h���\�t�g�E�F�A�ł��B
���ɊJ�����I������mayu��fork���邱�Ƃɂ��AWindows Vista�ȍ~��OS�̃T�|�[�g
��ڎw���Ă��܂��B

�I���W�i����mayu�ł̓t�B���^�h���C�o�ɂ��L�[�̒u���������������Ă��܂������A
�{�v���W�F�N�g�ł͂����WH_KEYBOARD_LL�̃t�b�N��SendInput() API�ɕύX���܂��B
����ɂ��Amayu�قǂ̒�w�ł̋��͂�
�u���͊��҂ł��Ȃ��Ȃ���̂́A�h���C�o�ւ̏�����v���邱�ƂȂ��A
Vista�ȍ~��Windows(����64bit��)�ւ̑Ή���ڎw���܂��B


2. �t�@�C���\��

yamy.exe	... yamy32/yamy64�̂ǂ��炩���N�����郉���`��
yamy32		... 32bit��yamy�{��
yamy64		... 64bit��yamy�{��
yamy32.dll	... 32bit�Ńt�b�NDLL
yamy64.dll	... 64bit�Ńt�b�NDLL
yamyd32		... 64bit����32bit�v���Z�X���t�b�N���邽�߂̕⏕�v���O����
yamy.ini	... �ݒ�t�@�C��(mayu �ł̃��W�X�g���ݒ�ɑ���)
workaround.reg	... ����L�[���΍��pScancode Map���W�X�g���T���v��
*.mayu		... �L�[�o�C���h�ݒ�t�@�C��


3. �g�p���@

��{�I�Ȏg�p���@�́u���g���̗J�T�v�Ɠ����ł��B
http://mayu.sourceforge.net/mayu/doc/README-ja.html
���Q�Ƃ��ĉ������B

�ȉ��A�u���g���̗J�T�v�ƈقȂ镔���ɂ��ċL�ڂ��܂��B

3.1. �}�E�X�C�x���g�̒u��

�������̃}�E�X�C�x���g���L�[�C�x���g�Ɠ��l�ɒu���\�ł��B
�e�}�E�X�C�x���g��E1-�v���t�B�b�N�X�����[���I�ȃX�L�����R�[�h
�Ƃ��Ĉ����܂��B
# WH_KEYBOARD_LL���g��yamy�ł�E1-�v���t�B�b�N�X�̃L�[�R�[�h��
# ���E�����Ƃ��ł��Ȃ����߁A���ۂ̃L�[�R�[�h�ƏՓ˂���\���͂Ȃ��B

�}�E�X�C�x���g�̒u���̓f�t�H���g�ł̓I�t�ł��B
�L�������邽�߂ɂ�.mayu �t�@�C����

def option mouse-event = true

�ƋL�q���܂��B

�u���\�ȃ}�E�X�C�x���g�͈ȉ��̒ʂ�ł��B
# ()���͎g����^���X�L�����R�[�h
* �}�E�X�h���b�O Drag(E1-0x00)
* ���{�^�� LButton(E1-0x01)
* �E�{�^�� RButton(E1-0x02)
* ���{�^�� MButton(E1-0x03)
* �z�C�[���O�i WheelForward(E1-0x04)
* �z�C�[����� WheelBackward(E1-0x05)
* X�{�^��1 XButton1(E1-0x06)
* X�{�^��2 XButton1(E1-0x07)
* ���X�N���[��(�`���g)�E TiltRight(E1-0x08) ��Vista�ȍ~
* ���X�N���[��(�`���g)�� TiltLeft(E1-0x09) ��Vista�ȍ~

���̂���Drag�C�x���g�́A�����ꂩ��}�E�X�{�^�����������܂܃{�^����
�������ꏊ������ȏ�}�E�X���ړ��������ۂ�Down���������ADown������
�Ƀ{�^���𗣂���Up����������^���C�x���g�ł��B
Drag�C�x���g�����܂ł̈ړ�������臒l�̓s�N�Z���P�ʂ�

def option drag-threshold = 30

�̂悤�Ɏw�肵�܂��B臒l�Ƃ���0���w�肷���������臒l���w�肵�Ȃ�
�ꍇ�ADrag�C�x���g�͔������܂���B

������1��
WheelForward/WheelBackward/TiltRight/TiltLeft�ɂ͕����I��"Up"
�C�x���g������܂���̂ŁAyamy�����ł͉�����������Down/Up��
���C�x���g���������܂��B���̂��߂����̃C�x���g�����f�B�t�@�C�A
�ɂ��邱�Ƃ͂ł��܂���B

������2��
�L�[�C�x���g�Ɠ��l�Ƀ}�E�X�C�x���g���u�����v�E�B���h�E���g����
�R�[�h�𒲍����邱�Ƃ��ł��܂����A�L�[�C�x���g�ƈقȂ蒲������
�C�x���g�͎̂Ă܂���B����́u�����v���[�h���甲�����Ȃ��Ȃ�
�Ȃ����߂̑[�u�ł��B

������3��
Vista�ȍ~�ł�yamy��W�������ŋN�����Aoption mouse-event ��L����
�����ꍇ�A�Ǘ��Ҍ����̃A�v����(�u���̗L���ɂ�����炸)�}�E�X
�C�x���g���͂��Ȃ��Ȃ�܂��Byamy���Ǘ��Ҍ����ŋN������ΕW������
�E�Ǘ��Ҍ����ǂ���ɂ��}�E�X�C�x���g���͂��܂��B


3.2. NLS�L�[�̃G�X�P�[�v

���{����̏ꍇ�A���{�ꏈ���Ɏg���邢�����̃L�[�ɑ΂��Ă�
WH_KEYBOARD_LL�t�b�N�O�ɓ��ꏈ�����s���邽�߁Ayamy�ɂ����
����Ƀt�b�N�ł��܂���B
�ȉ��A�֋X�ケ���̃L�[��NLS�L�[(National Language Support Key)
�ƌĂт܂��B

�L�[�{�[�h���C�A�E�g�h���C�o�Ƃ���kbd106.dll��p���Ă���ꍇ��
NLS�L�[�͈ȉ���4�ł��B
# []���̓X�L�����R�[�h
* ���p�E�S�p[0x29]
* �p��(CapsLock)[0x3a]
* �Ђ炪��[0x70]
* ���ϊ�[0x7b]

�L�[�{�[�h���C�A�E�g�h���C�o�Ƃ���kbd101.dll��p���Ă���ꍇ��
NLS�L�[�͈ȉ���2�ł��B
# []���̓X�L�����R�[�h
* `(~)[0x29]
* CapsLock[0x3a]

������NLS�L�[���������t�b�N�ł��Ȃ����Ƃւ̑΍�Ƃ��Ă̓��W�X�g��
�� Scancode Map ���g���Ă����̃L�[����ꈵ������Ȃ��ʂ̃L�[��
�u����������@������܂��BScancode Map �̎d�l�ɂ��ẮA

http://www.microsoft.com/whdc/archive/w2kscan-map.mspx

�ɏ�񂪂���܂��B�܂��ȉ��̃T�C�g�̋L�q���Q�l�ɂȂ�܂��B

http://www.jaist.ac.jp/~fujieda/scancode.html
http://sgry.jp/articles/scancodemap.html

���ARC�łŊm�F��������ł� Windows7 �̏ꍇ�AHKEY_LOCAL_MACHINE
�� Scancode Map ���L���̂悤�ł��BRTM�łłǂ����͖��m�F�ł��B

�������Ă��� workaround.reg �͋�̓I�Ȓu�������̃T���v���ł��B
���̃T���v���ł͂����NLS�L�[�� E0 �v���t�B�b�N�X��t�����邱�Ƃɂ��A
�ʃL�[�ɕϊ����Ă��܂��B������ *.mayu �͂��� Scancode Map �̉��ł����
E0��t�����ꂽ�L�[�����������{���̃L�[�̂悤�ɓ��삷��悤��
�ݒ肪�ǉ�����Ă��܂��B

workaround.mayu �ɂ͂��̑΍�ɑΉ������ǉ������𒊏o���Ă��܂��̂ŁA
�Ǝ��� .mayu ���g���Ă���ꍇ�͂�����Q�l�ɂ��ĉ������B

�܂��u�p���L�[��Ctrl�L�[�̓���ւ��v���̒P���Ȓu�������ŏ\����
�ꍇ�͂����ɍi���� Scancode Map ���쐬���Ă��ǂ��ł��傤�B

workaround.reg �̂悤�ȁu���݂��Ȃ��L�[�ւ̒u�������v�ɂ��΍��
yamy�����삵�Ă��Ȃ��ꍇ�����̃L�[���@�\���Ȃ��Ȃ�Ƃ�������p
������܂��B

������workaround.reg�����̒u������(�ȉ��A������uNLS�L�[�̃G�X�P�[�v�v
�ƌĂ�)��yamy�̓��쒆�̂ݍs���@�\�������I�Ɏ������܂����B

yamy�N�����Ƀ��W�X�g����workaround.reg�����ɏ��������Ă���
(���O�A�E�g���邱�ƂȂ�)OS��Scancode Map�ǂݍ��܂�����A������
���W�X�g�������ɖ߂��܂��Byamy�I�����ɂ�(���W�X�g���͊��Ɍ���
�߂��Ă���̂�)�P��OS�ɍēǂݍ��݂݂̂��w�����܂��B
����ɂ��Ayamy�̓��쒆�̂�NLS�̃G�X�P�[�v���������܂��B

���A�X�N���[�����b�N(�ʃ��[�U�ւ̊ȈՃ��[�U�؂�ւ����܂�)�ł�
�G�X�P�[�v�̉����A�X�N���[���A�����b�N�ł̍ăG�X�P�[�v���s���܂��B

�g�p���郌�W�X�g����Windows7�ȊO�̏ꍇ�́A
HKEY_CURRENT_USER\KeyBoard Layout\Scancode Map
Windows7�̏ꍇ�́A
HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\KeyBoard Layout\Scancode Map
�ł��B

���̋@�\�̓f�t�H���g�ł͖����ł���A�L���ɂ��邽�߂ɂ� yamy.ini �ɂ����āA

escapeNLSKeys=0

�� 

escapeNLSKeys=1

�ɕύX���܂��B���������̋@�\�̗��p�ɍۂ��Ă͈ȉ��̓_�ɗ��ӂ��ĉ������B

* �����I�ȋ@�\�ł���\���ȓ�����т��Ȃ��댯�������܂��B

* yamy�����s���郆�[�U��SeDebugPrivilege�������K�v�ł��BAdministrators
  �O���[�v�ɑ����郆�[�U�͊���ł��̓����������Ă��܂��B
  ������UAC���L���ȏꍇ�́A�����ĊǗ��҂Ƃ��Ď��s����K�v������܂��B

* ���ɑΏۂƂȂ�NLS�L�[��Scancode Map�Œu���������Ă���ꍇ��
  �G�X�P�[�v�͍s���܂���B

* �G�X�P�[�v�̂��߃��W�X�g�������������Ă����u�̊Ԃ�yamy��
  �ُ�I�������ꍇ�A�G�X�P�[�v�p��Scancode Map�����W�X�g����
  �c��܂��B���̏ꍇ�Aregedit���g���Č��ɖ߂��ĉ������B

* ��L�̏u�ԈȊO��yamy���ُ�I�������ꍇ�A���W�X�g���͌��ɖ߂���
  ���܂����AOS������Scancode Map�͎c���Ă���̂ŁA��U���O�I�t�E
  ���O�I�����Č��ɖ߂����Ayamy���ċN�����ĉ������B


3.3. &CancelPrefix�֐�

Prefix��Ԃ������I�ɉ������邽�߂̊֐�&CancelPrefix���ǉ�����܂����B
One Shot���f�B�t�@�C�A�Ɏw�肵�Ă���L�[�𗣂����ۂ�Prefix����������
���߂ɓ������܂����B

3.4. ���̑�

* �C���X�g�[���͂���܂���Byamy-0.02.zip ��C�ӂ̃t�H���_�ɓW�J���A
  yamy.exe �����s���ĉ������B

* ���W�X�g���ł͂Ȃ��Ayamy.exe �Ɠ����t�H���_�ɂ��� yamy.ini ��
  �ݒ���̕ۑ����܂��B

* �ݒ�t�@�C���̓z�[���f�B���N�g���ł͂Ȃ��Ayamy.exe �̂���t�H���_��
  .mayu �Ƃ����t�@�C�����Œu���ĉ������B

* �L�[�{�[�h�̎�ʂ̔���͍s���܂���̂ŁA����N�����Ƀ��j���[��
  �u�I���v�œK�؂Ȑݒ��I�����ĉ������B

* �����[�g�f�X�N�g�b�v�ł̃��O�I�����ł��N����}�����܂���B


4. ���������E�s�

* ��ʃ��b�N���̓L�[�u���������܂���B�܂��A���̐����ɂ���ʃ��b�N
  �ւ̑J�ڎ��ɉ����������Ă���L�[���������ꍇ�A���̃L�[���������ςȂ�
  �ɂȂ邱�Ƃ�����܂��B���̏ꍇ�A���̃L�[���󉟂����邱�Ƃɂ����
  �������ςȂ����������܂��B���� Alt �L�[���������ςȂ����ƁA�p�X���[�h
  �����͂ł��Ȃ��Ȃ�̂Œ��ӂ��ĉ������B

* Vista�ł̕ی샂�[�h�L����IE7�ł̓L�[�}�b�v���O���[�o���ɂȂ�܂��B
  IE8�ł͖�肠��܂���B

* ���[�U���[�h�ł̃t�b�N�̂��߁A�ȉ��̏ꍇ�͋@�\���Ȃ��Ǝv���܂��B
  - WH_KEYBOARD_LL ���t�b�N���鑼�A�v���Ƃ̋���
  - DirectInput ���g�����v���O����

* Pause�L�[�̂悤�ɃX�L�����R�[�h�� E1 �v���t�B�b�N�X���t�����L�[
  �͒u���������܂���B���̂悤�ȃL�[���g�p�������ꍇ�� Scancode Map
  ���W�X�g���𕹗p���ĉ������B

* �Z�L�����e�B�\�t�g�ɂ���Ă̓t�b�NDLL�̃C���X�g�[�����u���b�N�����
  �ꍇ������܂��̂ŁA���̏ꍇ�� yamy32/yamy64 ���O�Ƃ��ēo�^���ĉ������B


5. �r���h���@

Visual Studio 2008 Professional + Windows SDK v6.1�Ŋm�F���Ă��܂��B
yamy�̃r���h�ɂ�x64�p�R���p�C�����K�v�ɂȂ�܂����AVisual Studio 2008
�̊���̃C���X�g�[���ł̓C���X�g�[������܂���̂Œǉ��ŃC���X�g�[��
����K�v������܂��B

5.1.
yamy �� boost_1_38_0 �̃\�[�X����肵�A�ȉ��̔z�u�ɂēW�J���܂��B

./
   |
   +---boost_1_38_0/ ... http://www.boost.org/ ������肵���A�[�J�C�u��W�J
   |
   +---yamy/ ... "git clone git://git.sourceforge.jp/gitroot/yamy/yamy.git"���ɂ��W�J
       |
       +---proj/ ...
       +---tools/ ...

5.2.
yamy/proj/yamy.sln �� Visual Studio �ŊJ���A�\�����[�V�������r���h���܂��B

5.3.
yamy/{Debug,Release}/ �ȉ��Ƀo�C�i���� zip �p�b�P�[�W����������܂��B


6. ���쌠�E���C�Z���X

YAMY�̒��쌠�E���C�Z���X�͈ȉ��̒ʂ�ł�:

  Yet Another Mado tsukai no Yuutsu(YAMY)

    Copyright (C) 2009, KOBAYASHI Yoshiaki <gimy@users.sourceforge.jp>
      All rights reserved.

    Redistribution and use in source and binary forms,
    with or without modification, are permitted provided
    that the following conditions are met:

      1. Redistributions of source code must retain the above copyright
         notice, this list of conditions and the following disclaimer.
      2. Redistributions in binary form must reproduce the above
         copyright notice, this list of conditions and the following
         disclaimer in the documentation and/or other materials provided
         with the distribution.
      3. The name of the author may not be used to endorse or promote
         products derived from this software without specific prior
         written permission. 

    THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
    STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
    IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
    THE POSSIBILITY OF SUCH DAMAGE.


YAMY�̔h�����ł���u���g���̗J�T�v�̒��쌠�E���C�Z���X�͈ȉ��̒ʂ�ł�:

  ���g���̗J�T

    Copyright (C) 1999-2005, TAGA Nayuta <nayuta@users.sourceforge.net>
      All rights reserved.

    Redistribution and use in source and binary forms,
    with or without modification, are permitted provided
    that the following conditions are met:

      1. Redistributions of source code must retain the above copyright
         notice, this list of conditions and the following disclaimer.
      2. Redistributions in binary form must reproduce the above
         copyright notice, this list of conditions and the following
         disclaimer in the documentation and/or other materials provided
         with the distribution.
      3. The name of the author may not be used to endorse or promote
         products derived from this software without specific prior
         written permission. 

    THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
    INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
    STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
    IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
    THE POSSIBILITY OF SUCH DAMAGE.


YAMY�����p���Ă���Boost���C�u�����̃��C�Z���X�͈ȉ��̒ʂ�ł�:

  Boost Software License - Version 1.0 - August 17th, 2003

  Permission is hereby granted, free of charge, to any person or organization
  obtaining a copy of the software and accompanying documentation covered by
  this license (the "Software") to use, reproduce, display, distribute,
  execute, and transmit the Software, and to prepare derivative works of the
  Software, and to permit third-parties to whom the Software is furnished to
  do so, all subject to the following:

  The copyright notices in the Software and this entire statement, including
  the above license grant, this restriction and the following disclaimer,
  must be included in all copies of the Software, in whole or in part, and
  all derivative works of the Software, unless such copies or derivative
  works are solely in the form of machine-executable object code generated by
  a source language processor.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
  SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
  FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.


7. �ӎ�

�����܂ł��Ȃ��u���g���̗J�T�v���Ȃ����YAMY�͑��݂����܂���ł����B
�u���g���̗J�T�v�̍�҂ł��鑽��ޗR������ƊJ���ɍv���������X�ɂ���
����؂�Đ[������\���グ�܂��B


8. ����

2009/08/?? ver.0.02

* Vista�ł̌������i���s���ɕW�������A�v���̃L�[�}�b�v���O���[�o���ɂȂ�����C��

* NLS�L�[�̃G�X�P�[�v�@�\�������I�Ɏ���

* &CancelPrefix�֐���ǉ�

* �}�E�X�C�x���g�̒u���@�\��ǉ�

* �����[�g�f�X�N�g�b�v���̋N���}����p�~

* �r���h�V�X�e����ύX
  - makefile����VC++2008�̃v���W�F�N�g�Ɉڍs
  - makefunc��zip�ł̃p�b�P�[�W�쐬��JScript�ōĎ���

* �s��C��
  - �n���O���Ă���v���Z�X������ƏI���ł��Ȃ�(�`�P�b�g#17643)
  - �E�V�t�g�������ꂽ�܂܂ɂȂ邱�Ƃ�����(�`�P�b�g#17607)
  - yamy�̃_�C�A���O�������ۂ�5�b���x�t���[�Y���邱�Ƃ�����(�`�P�b�g#17767)
  - ���b�ԃL�[���͂��؂邱�Ƃ�����(�`�P�b�g#17576)

2009/06/28 ver.0.01

�������[�X
�ȉ��́u���g���̗J�T�v�̍ŏI�ł���̕ύX�_

* �L�[���͒u�����h���C�o���烆�[�U���[�h�ɕύX(NO_DRIVER�}�N��)
  - �h���C�o�ւ̃A�N�Z�X��r��
  - �L�[���͂̃t�b�N�� WH_KEYBOARD_LL ���g��
  - �L�[�C�x���g������SendInput() API���g��
  - WM_COPYDATA �ł̒ʒm�ŃX�g�[������ꍇ������̂Ń��[���X���b�g�Œʒm(USE_MAILSLOT�}�N��)
  - ���d���b�Z�[�W�΍�Ƃ��� !PM_REMOVE �ȃ��b�Z�[�W���t�b�NDLL�Ŗ���
  - RShift��E0���t������邱�ƂɑΉ�����{104,109}.mayu��workaround��ǉ�

* 64bit�Ή�(MAYU64�}�N��)
  - GetWindowLong -> GetWindowLongPtr ���̎g�pAPI�ύX
  - LONG -> LONG_PTR ���̌^�ύX
  - HWND �� DWORD �ɃL���X�g���� 32bit<->64bit �Ԃŋ��L
  - 64bit ���� 32bit �v���Z�X�ւ̃t�b�N���C���X�g�[������ yamyd.cpp ��V��
  - obj�̏o�̓f�B���N�g����32bit��64bit�ŕ�����
  - WPARAM/LPARAM �̎��̂� 64bit �ł͈قȂ�̂ŁAload_ARGUMENT()�̃I�[�o�[���[�h��ǉ�
  - INVALID_HANDLE_VALUE=0xffffffff �Ɖ��肵�Ȃ�
  - notifyCommand()�𖳌���(�ꎞ�I�[�u)

* �C���X�g�[�������ł̎��s
  - �C���X�g�[�����r���h�Ώۂ���O��
  - ���W�X�g���̑ւ�� yamy.ini �Őݒ肷��(USE_INI�}�N��)

* ���O�֘A
  - hook.cpp �Ƀf�o�b�O�}�N���ǉ�
  - �f�o�b�K���̓���v���Z�X�ł̓t�b�NDLL�̃f�o�b�O�o�͂�}�~
  - ���O���t�@�C���ɋL�^����@�\��ǉ�(LOG_TO_FILE�}�N��:����͖���)
  - OS���̃L�[����������Ԃ����O�o�͂���u�`�F�b�N�v�@�\��ǉ�

* �o�O�C��
  - Engine::setFocus()�ŃN���b�V����������C��
  - KeyIterator::KeyIterator()�ŋ󃊃X�g��������assert fail��������C��
  - �f�o�b�O�r���h�ł̓f�o�b�O�Ń����^�C���������N����

* ���̑�
  - exe��dll�̃x�[�X�l�[���� mayu ���� yamy �ɕύX
  - 32bit/64bit �� exe ���Ăѕ����郉���`���𓱓�
  - �t�b�NDLL�̏����������̑唼�� DllMain ����O����
  - boost::regex �̍X�V�ɔ��� tregex::use_except �̖������폜
  - VC++9���f�t�H���g�̃R���p�C���ɕύX
  - LOGNAME -> USERNAME
  - -GX �� -EHsc �ɕύX
  - nmake �̃I�v�V�������� -k ���폜
  - �t�b�N���������邽�� WM_NULL ���u���[�h�L���X�g
