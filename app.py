from flask import Flask,request
from pymongo import MongoClient
import json

cluster= MongoClient("mongodb+srv://krishnareddy:1234567890@diploma.1v5g6.mongodb.net/")
db=cluster['busIot']
coll=db['bus']

app=Flask(__name__)

@app.route('/')
def index():
    return "Application started"

@app.route('/verify')
def verify():
    id=request.args.get('id')
    data=coll.find_one({"st_id":id})
    data=data['status']
    data=json.dumps(data)
    print(data)
    return data

if __name__=="__main__":
    app.run(host='0.0.0.0',port=5000)