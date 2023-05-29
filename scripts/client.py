# coding: cp1251
import socket
import sys
import time
# ������� ������ ������� � �����
addr = ('172.20.215.250', 9999)

# ���������� ����������
n = 1; rec = 0
# ����������� ����

 # �������� ������, ��� TCP (SOCK_STREAM)
tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

print("connecting to", addr)
tcp_socket.connect(addr)
print("connected")

while True:
 # ����������� try: ... except: ��� ��������� ����������
 try:
 # �������� ����� �� ������
   print("sleeping")
   time.sleep(1)
   tcp_socket.send(b'\xaa\xbb\xcc')
   print("sent")
 # ��������� 2 ���� �� �������
   data = tcp_socket.recv(2)
   print("received")
 # ����������� ���������� �� ������� ���� � �����
#   rec = int.from_bytes(data, byteorder = 'big')
   print("�������� �� �������: ", repr(data))
 # �������� ������
#   tcp_socket.close()
 # ���������� ��������
   n+=1
 # �������� 1 �������
   time.sleep(1)
 except socket.error:
   print("������ �����������!")