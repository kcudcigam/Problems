var
  i,j,k,n,m,l,r,a1,b1,c1,d1,l1,r1:longint;
  a,b,c,d:array[0..400010]of int64;
  num:int64;
  s,s1:char;
  f:boolean;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=c[(l+r) div 2];
         repeat
           while c[i]>x do
            inc(i);
           while x>c[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=c[i];
                c[i]:=c[j];
                c[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
procedure sort1(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]>x do
            inc(i);
           while x>a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort1(l,j);
         if i<r then
           sort1(i,r);
      end;
procedure sort2(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=b[(l+r) div 2];
         repeat
           while b[i]>x do
            inc(i);
           while x>b[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort2(l,j);
         if i<r then
           sort2(i,r);
      end;
begin
  assign(input,'debate.in');
  reset(input);
  assign(output,'debate.out');
  rewrite(output);
  readln(n);
  l:=0; r:=0; a1:=0; b1:=0; c1:=0; d1:=0;
  a[0]:=-100; b[0]:=-100; c[0]:=-100; d[0]:=-100;
  for i:=1 to n do
    begin
      readln(s,s1,m);
      if s='1'
      then l:=l+1;
      if s1='1'
      then r:=r+1;
      if (s='1') and (s1='0')
      then begin a1:=a1+1; a[a1]:=m; end;
      if (s='0') and (s1='1')
      then begin b1:=b1+1; b[b1]:=m; end;
      if (s='0') and (s1='0')
      then begin c1:=c1+1; c[c1]:=m; end;
      if (s='1') and (s1='1')
      then begin d1:=d1+1; d[d1]:=m; end;
    end;
  if c1>0
  then sort(1,c1);
  num:=0;
  if l>r
  then begin
         l1:=d1-b1; r1:=r;
         for i:=1 to d1 do
           num:=num+d[i];
         for i:=1 to b1 do
           num:=num+b[i];
         if a1>0
         then sort1(1,a1);
         for i:=1 to a1 do
           begin
             if l1>=0
             then break
             else begin num:=num+a[i]; l1:=l1+1; r1:=r1-1; end;
           end;
         j:=1; f:=true;
         while f=true do
           begin
             if (l1=0) and (i>a1)
             then break;
             if r1-1>=0
             then begin
                    if (l1-1>=0) and (c[j]>a[i]) and (j<=c1)
                    then begin dec(l1); dec(r1); num:=num+c[j]; inc(j); end
                    else begin inc(l1); dec(r1); num:=num+a[i]; inc(i); end;
                  end
             else break;
           end;
         writeln(num);
       end
  else begin
         r1:=d1-a1; l1:=l;
         for i:=1 to d1 do
           num:=num+d[i];
         for i:=1 to a1 do
           num:=num+a[i];
         if b1>0
         then sort2(1,b1);
         for i:=1 to b1 do
           begin
             if l1>=0
             then break
             else begin num:=num+b[i]; l1:=l1-1; r1:=r1+1; end;
           end;
         j:=1; f:=true;
         while f=true do
           begin
             if (r1=0) and (i>b1)
             then break;
             if l1-1>=0
             then begin
                    if (r1-1>=0) and (c[j]>b[i]) and (j<=c1)
                    then begin dec(l1); dec(r1); num:=num+c[j]; inc(j); end
                    else begin inc(r1); dec(l1); num:=num+b[i]; inc(i); end;
                  end
             else break;
           end;
         writeln(num);
       end;
  close(input);
  close(output);
end.
