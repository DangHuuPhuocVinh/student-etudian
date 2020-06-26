var N1 = document.getElementById('N1').value;
var n1 = Number(N1);
var N2 = document.getElementById('N2').value;
var n2 = Number(N2);
var OP = document.getElementById('operator');
var op = OP.value;
var resSpan = document.getElementById('result');
// var res = 0;

switch(OP)
{
    case "+":
        {
            var res = n1 + n2;
            break;
        }
    case "-":
        {
            var res = n1 - n2;
            break;
        }  
    case "*":
        {
            var res = n1 * n2;
            break;
        }
     case "/":
        {
            var res = n1 / n2;
            break;
        }
}

resSpan.textContent = res;
event.preventDefault();