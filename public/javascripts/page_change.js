var app = angular.module("myApp", ["ngRoute"]);

app.config(function($routeProvider) {
    $routeProvider
    .when("/", {
        templateUrl : "home.html"
    })
    .when("/home",{
        templateUrl : "home.html"
    })
    .when("/detail", {
        templateUrl : "about.html"
    })
    
});