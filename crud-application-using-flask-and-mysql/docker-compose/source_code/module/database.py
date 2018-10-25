'''
Created on Jan 10, 2017

@author: hanif
'''

import pymysql

class Database:
    def connect(self):
        return pymysql.connect("db","root","dev","weather" )


    def read(self, id):
        con = Database.connect(self)
        cursor = con.cursor()            
        try: 
            if id == None:
                cursor.execute("SELECT * FROM sensor_data order by id asc")
                row_headers=[x[0] for x in cur.description]
                rv = cur.fetchall()
                json_data=[]
                for result in rv:
                    json_data.append(dict(zip(row_headers,result)))
                return json.dumps(json_data)
            else: 
                cursor.execute("SELECT * FROM sensor_data where id = %s order by id asc", (id,))
                return ()
        except:
            return ()
        finally:
            con.close()


    def read(self, id):
        con = Database.connect(self)
        cursor = con.cursor()
        
        try: 
            if id == None:
                cursor.execute("SELECT * FROM sensor_data order by id asc")
            else: 
                cursor.execute("SELECT * FROM sensor_data where id = %s order by id asc", (id,))

            return cursor.fetchall()
        except:
            return ()
        finally:
            con.close()



    def insert(self,data):
        con = Database.connect(self)
        cursor = con.cursor()
     
        try:
            cursor.execute("INSERT INTO sensor_data(temp,humidity,pressure) VALUES(%s, %s, %s)", (data['temp'],data['humidity'],data['address'],))
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
