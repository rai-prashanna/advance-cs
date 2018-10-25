'''
Created on Jan 10, 2017

@author: hanif
'''
from flask import Flask, flash, render_template, redirect, url_for, request, session, jsonify

import pymysql
import json


class Database:
    def connect(self):
        return pymysql.connect("localhost","dev","dev","weather" )

    def read(self, id):
        con = Database.connect(self)
        cursor = con.cursor()
        try: 
            if id == None:
                cursor.execute("SELECT * FROM sensor_data order by id asc")
            else: 
                cursor.execute("SELECT * FROM sensor_data where id = %s order by id asc", (id,))
            
            return jsonify(data=cursor.fetchall())
        except:
            return ()
        finally:
            con.close()



    def insert(self,data):
        con = Database.connect(self)
        cursor = con.cursor()
     
        try:
            cursor.execute("INSERT INTO sensor_data (temp, humidity, pressure) VALUES(%s, %s, %s)", (data['temp'],data['humidity'],data['pressure'],))
            con.commit()
            
            return True
        except:
            con.rollback()
            
            return False
        finally:
            con.close()
            
    def update(self, id, data):
        con = Database.connect(self)
        cursor = con.cursor()
        
        try:
            cursor.execute("UPDATE phone_book set name = %s, phone = %s, address = %s where id = %s", (data['name'],data['phone'],data['address'],id,))
            con.commit()
            
            return True
        except:
            con.rollback()
            
            return False
        finally:
            con.close()
        
    def delete(self, id):
        con = Database.connect(self)
        cursor = con.cursor()
        
        try:
            cursor.execute("DELETE FROM phone_book where id = %s", (id,))
            con.commit()
            
            return True
        except:
            con.rollback()
            
            return False
        finally:
            con.close()
