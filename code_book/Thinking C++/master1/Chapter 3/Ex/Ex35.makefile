# �������� ��� ������ �� ���������� ���������� (�� ������ ������) make-����.
# �� ������� make ������ ��������� ������� ������ ���������, � �� �������
# make debug - ������ c ���������� ����������� ����
CPP = g++
SOURCE_FILE = Ex34.cpp
common:
	$(CPP) $(SOURCE_FILE)
debug:
	$(CPP) -D NDEBUG $(SOURCE_FILE)