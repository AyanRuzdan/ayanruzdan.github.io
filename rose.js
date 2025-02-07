var svg = document.getElementById('svg');
var bloomText = document.querySelector('.bloom-text');

svg.addEventListener('mouseenter', function () {
    bloomText.style.opacity = '0';
    for (var i = 0; i <= 14; i++) {
        document.getElementById('animate' + i).beginElement();
    }
});

svg.addEventListener('mouseleave', function () {
    setTimeout(() => bloomText.style.opacity = '1', 12000);
});
