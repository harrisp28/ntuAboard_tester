from flask import Flask, render_template, request, jsonify
import subprocess

app = Flask(__name__)

def test(program): 
    try:
        subprocess.run(['make', 'install', 'MAIN=./tests/'+program], check=True)
        print("Command executed successfully")
    except subprocess.CalledProcessError as e:
        print("Error:", e)
    
    subprocess.run(['make', 'clean', 'MAIN=./tests/'+program], check=True)
    return 'Testing '+program

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/ledsB', methods=['GET', 'POST'])
def ledsB():
    if request.method == 'POST':
        response = test('ledsB')
        return jsonify({'result': response})
    return render_template('index.html')

@app.route('/ledsC', methods=['GET', 'POST'])
def ledsC():
    if request.method == 'POST':
        response = test('ledsC')
        return jsonify({'result': response})
    return render_template('index.html')

@app.route('/ledsD', methods=['GET', 'POST'])
def ledsD():
    if request.method == 'POST':
        response = test('ledsD')
        return jsonify({'result': response})
    return render_template('index.html')

@app.route('/lcd', methods=['GET', 'POST'])
def lcd():
    if request.method == 'POST':
        response = test('lcd')
        return jsonify({'result': response})
    return render_template('index.html')

@app.route('/keypad', methods=['GET', 'POST'])
def keypad():
    if request.method == 'POST':
        response = test('keypad')
        return jsonify({'result': response})
    return render_template('index.html')

@app.route('/thermometer', methods=['GET', 'POST'])
def thermometer():
    if request.method == 'POST':
        response = test('thermometer')
        return jsonify({'result': response})
    return render_template('index.html')

@app.route('/adc', methods=['GET', 'POST'])
def adc():
    if request.method == 'POST':
        response = test('adc')
        return jsonify({'result': response})
    return render_template('index.html')



if __name__ == '__main__':
    app.run(debug=True)
