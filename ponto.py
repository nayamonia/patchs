#!/bin/python
import datetime

entrada1 = '08:28'
saida1 = '12:40'
entrada2 = '09:18'
saida2 = '11:47'
entrada3 = '13:47'
jornada = '08:48'

hora_atual = '%s:%s' % (datetime.datetime.now().time().hour, \
                        datetime.datetime.now().time().minute)
offset = datetime.datetime.strptime('1900-01-01', '%Y-%m-%d')

i = datetime.datetime.strptime(entrada1, '%H:%M')
o = datetime.datetime.strptime(saida1, '%H:%M')
i2 = datetime.datetime.strptime(entrada2, '%H:%M')
o2 = datetime.datetime.strptime(saida2, '%H:%M')
i3 = datetime.datetime.strptime(entrada3, '%H:%M')
o3 = datetime.datetime.strptime(hora_atual, '%H:%M')
j = datetime.datetime.strptime(jornada, '%H:%M')

turno1 = (o-i)
turno2 = (o2-i2)
turno3 = (o3-i3)
total = turno2 + turno1 + turno3
total = turno1 + turno3
falta = j - total - offset
saida = o3 + falta - offset
#extra = total.time  - j

print 'Check Point'
print '\nTurno 1: %s' % turno1
#print 'Turno 2: %s' % turno2
print 'Turno 3: %s\n' % turno3
print 'Hora Atual: %s' % hora_atual
print 'Acumulado do dia: %s' % total
print 'Faltam: %s\n'% falta
#print 'Extras: %s\n'% extra
print 'Saida Ideal: %s\n'% saida
