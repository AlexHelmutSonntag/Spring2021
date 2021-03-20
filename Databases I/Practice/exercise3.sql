--To Display the tables used in the exercise.

select  * from emp;
select *from dept;
select * from sal_cat;

select ename from emp where mod(sal,15) =0;

select ename from emp where hiredate  >to_date('1982.01.01','yyyy.mm.dd');


select ename from emp where substr(ename,2,1)  = 'A';

select ename from emp where instr(ename,'L',1,2) > 0;


select ename , substr(ename,-3,3) from emp;
--does the same 
select ename , substr(ename,-3) from emp;


select ename ,substr(ename,-2,1) from emp where substr(ename,-2,1) = 'T';

select sal,round(sqrt(sal),2), trunc(round(sqrt(sal),2),0)from emp;


select hiredate,to_char(hiredate,'Month')
from emp where ename = 'ADAMS';

select ename ,hiredate, trunc(sysdate-hiredate)days_worked from emp where ename = 'ADAMS';


select ename ,hiredate from Emp where to_char(hiredate,'Day') like 'Tuesday%';

select e1.ename mgr_name ,e2.ename emp_name from emp e1, emp e2 where e1.empno = e2.mgr 
and length(e1.empno )= length(e2.mgr); 

select category , ename from emp, sal_cat where sal between lowest_sal and highest_sal and category =1;


select category, ename from emp ,sal_cat where sal between lowest_sal and highest_sal 
and mod(category,2) = 0;



select k.hiredate - j.hiredate K_J from emp k , emp j where k.ename = 'KING'and j.ename = 'JONES';


select to_char(last_day(hiredate),'Day') from emp where ename = 'KING';


select to_char(trunc(hiredate,'Month'),'Day')from emp where ename ='KING';

select to_char(trunc(hiredate,'Month')) from emp where ename = 'KING';


select ename, dname, category from emp e, dept d, sal_cat c where dname like'%C%' 
AND sal between lowest_sal and highest_sal and category >=4 AND e.deptno = d.deptno;


select ename ,sal, rpad('0',round(sal,-3)/1000,'#') from emp;
