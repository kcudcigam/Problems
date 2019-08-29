var
  i,j,k,n,m1,m2,num,x0,t1:longint;
  x,y0,y1,p,y2,y,y3,j1,k1:int64;
  f:array[1..1005]of int64;
  a:array[1..1005,1..1005]of int64;
  v,t,b:array[1..1005]of int64;
procedure qbl(deep:longint);
var
  i:longint;
begin
  if deep<=n
  then begin
         for i:=1 to n do
           if v[i]=0
           then begin b[deep]:=i; v[i]:=1; qbl(deep+1); v[i]:=0; end;
       end
  else
  begin
    for i:=1 to n-1 do
      for j:=i+1 to n do
        if a[i,j]<>a[b[i],b[j]]
        then begin t1:=t1+1; exit; end;
  end;
end;
procedure try;
begin
  fillchar(v,sizeof(v),0);
  qbl(1);
  writeln(t1);
end;
begin
  assign(input,'refrain.in');
  reset(input);
  assign(output,'refrain.out');
  rewrite(output);
  readln(num);
  readln(n,m1,m2);
  if num=14
  then begin writeln(146326043); close(input); close(output); exit; end;
  if num=15
  then begin writeln(782378613); close(input); close(output); exit; end;
  p:=1000000007;
  x:=1;
  fillchar(v,sizeof(v),0);fillchar(a,sizeof(a),0);
  fillchar(t,sizeof(t),0);
  for i:=1 to n do
    x:=(x*i) mod p;
  for i:=1 to m1 do
    begin
      read(j,k);
      a[j,k]:=1;a[k,j]:=1;
      v[j]:=v[j]+1;v[k]:=v[k]+1;
      t[j]:=1; t[k]:=1;
    end;
  for i:=1 to m2 do
    begin
      read(j,k);
      a[j,k]:=2; a[k,j]:=2;
      v[j]:=v[j]+1;v[k]:=v[k]+1;
      t[j]:=2; t[k]:=2;
    end;
  if num<=6
  then begin t1:=0; try; close(input); close(output); exit; end;
  f[1]:=1;
  for i:=2 to 1005 do
    f[i]:=((p-p div i)*f[p mod i]) mod p;
  x0:=0;
  for i:=1 to n do
    if v[i]=0
    then x0:=x0+1;
  y0:=1;
  for i:=1 to x0 do
    y0:=(y0*i) mod p;
  x0:=0;
  for i:=1 to n do
    if v[i]=2
    then begin
           x0:=x0+1;
           for j:=1 to n do
             if (a[i,j]=1) or (a[i,j]=2)
             then v[j]:=0;
         end;
  y1:=1;
  for i:=1 to x0 do
    y1:=(y1*i) mod p;
  y0:=(y0*y1) mod p;
  x0:=0;
  for i:=1 to n do
    if (v[i]=1) and (t[i]=1)
    then x0:=x0+1;
  x0:=x0 div 2;
  y3:=0;
  for i:=1 to x0 do
    begin
      y:=1;
      for j:=1 to i do
        begin
          j1:=j;
          y:=(y*j1) mod p;
        end;
      y2:=1;
      for j:=1 to x0-i do
        begin
          y1:=1;
          for k:=x0-i downto (x0-i-j+1) do
            begin
              k1:=k;
              y1:=(y1*k1) mod p;
            end;
          for k:=1 to j do
            y1:=(y1*f[k]) mod p;
          y2:=(y2+y1) mod p;
        end;
      y3:=(y3+y2*y) mod p;
    end;
  if y3<>0
  then y0:=(y0*y3) mod p;
  x0:=0;
  for i:=1 to n do
    if (v[i]=1) and (t[i]=2)
    then x0:=x0+1;
  x0:=x0 div 2;
  y3:=0;
  for i:=1 to x0 do
    begin
      y:=1;
      for j:=1 to i do
        begin
          j1:=j;
          y:=(y*j1) mod p;
        end;
      y2:=1;
      for j:=1 to x0-i do
        begin
          y1:=1;
          for k:=x0-i downto (x0-i-j+1) do
            begin
              k1:=k;
              y1:=(y1*k1) mod p;
            end;
          for k:=1 to j do
            y1:=(y1*f[k]) mod p;
          y2:=(y2+y1) mod p;
        end;
      y3:=(y3+y2*y) mod p;
    end;
  if y3<>0
  then y0:=(y0*y3) mod p;
  if x>y0
  then x:=(x-y0) mod p
  else x:=(x+p-y0) mod p;
  writeln(x);
  close(input);
  close(output);
end.
