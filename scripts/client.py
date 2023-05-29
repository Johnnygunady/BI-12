# coding: cp1251
import socket
import sys
import time
# задание адреса сервера и порта
addr = ('172.20.215.250', 9999)

# объявление переменных
n = 1; rec = 0
# бесконечный цикл

 # открытие сокета, тип TCP (SOCK_STREAM)
tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

print("connecting to", addr)
tcp_socket.connect(addr)
print("connected")

while True:
 # конструкция try: ... except: для обработки исключений
 try:
 # передача числа на сервер
   print("sleeping")
   time.sleep(1)
   tcp_socket.send(b'\xaa\xbb\xcc')
   print("sent")
 # получение 2 байт от сервера
   data = tcp_socket.recv(2)
   print("received")
 # конвертация полученных от сервера байт в число
#   rec = int.from_bytes(data, byteorder = 'big')
   print("Получено от сервера: ", repr(data))
 # закрытие сокета
#   tcp_socket.close()
 # увеличение счётчика
   n+=1
 # задержка 1 секунда
   time.sleep(1)
 except socket.error:
   print("Ошибка подключения!")