

			���g���̗J�T�h���C�o


1. �R���p�C�����@

	Windows 200 DDK �� Visual C++ 6.0 �� build ���[�e�B���e�B��
	�p���ăR���p�C�����܂��B

	> cd mayu\d
	> build
	> cd nt4
	> build

	mayud.sys �� %windir%\system32\drivers\ �փR�s�[�� test.reg ��
	���͂���΁A�蓮�Ńf�o�C�X�� on/off �ł��܂��B(���� Windows
	NT4.0 �̏ꍇ�� mayudnt4.sys �� mayud.sys �Ƃ������O�ŃR�s�[)


2. �g����

	mayud �𓮍삳�����

	      \\.\MayuDetour1

	�Ƃ����f�o�C�X���ł��܂��B���̃f�o�C�X�� GENERIC_READ |
	GENERIC_WRITE �ŊJ���܂��B

	ReadFile / WriteFile �ł́A�ȉ��̍\���̂��g���܂��B�f�o�C�X��
	�J�������ƂɁAReadFile ����ƃ��[�U�[�����͂����L�[���擾�ł�
	�܂��BWriteFile ����ƃ��[�U�����������L�[����͂������̂悤�� 
	Windows �𑀍삷�邱�Ƃ��ł��܂��B

	struct KEYBOARD_INPUT_DATA
	{
	  enum { BREAK = 1,
		 E0 = 2, E1 = 4,
		 TERMSRV_SET_LED = 8 };
	  enum { KEYBOARD_OVERRUN_MAKE_CODE = 0xFF };
	  
	  USHORT UnitId;
	  USHORT MakeCode;
	  USHORT Flags;	
	  USHORT Reserved;
	  ULONG ExtraInformation;
	};

	UnitId �� Reserved �͏�� 0 �ł��BExtraInformation �ɒl��ݒ�
	����ƁAWM_KEYDOWN �Ȃǂ̃��b�Z�[�W���������� 
	GetMessageExtraInfo() API �ł��̒l���擾���邱�Ƃ��ł��܂��B
	MakeCode �̓L�[�{�[�h�̃X�L�����R�[�h�ł��BFlags �� BREAK, E0,
	E1, TERMSRV_SET_LED ���g�ݍ��킳���Ă��܂��BBREAK �̓L�[�𗣂�
	���Ƃ��AE0 �� E1 �͊g���L�[���������Ƃ��ɐݒ肳��܂��B


3. �o�O

	* ReadFile �� ERROR_OPERATION_ABORTED �Ŏ��s�����ꍇ������x 
	  ReadFile ����K�v������܂��B

	* �����̃X���b�h���� mayud �f�o�C�X�� read �����
	  MULTIPLE_IRP_COMPLETE_REQUESTS (0x44) �ŗ����邱�Ƃ�����悤
	  �ł��B�Č����͕s���B

	* ReadFile ����ƃ��[�U�[�����͂���܂ŉi���ɋA���Ă��܂���B
	  NT4.0 �Ȃ�ΕʃX���b�h�� CancelIo ���邱�Ƃ� ReadFile ���L��
	  ���Z�����邱�Ƃ��ł��܂����AWindows 2000 �ł͕��@������܂�
	  ��B

	* PnP �͍l�����Ă��܂���B�܂�A�L�[�{�[�h�������藣������
	  ����Ƃǂ��Ȃ邩�킩��܂���B

	* �L�[�{�[�h����ȏ゠��Ƃ��ł��A�f�o�C�X�͈�����ł��܂�
	  ��B
