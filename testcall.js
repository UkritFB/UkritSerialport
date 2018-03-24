function main()
{
	b();
	console.log("End");
	a();
}
function b ()
{
	for (var i = 10 - 1; i >= 0; i--) 
		{
			console.log(i);
		}
}
function a()
{
	console.log("A");
}
main();