package tyut.practice.onlineDisk.service;

import javax.servlet.RequestDispatcher;

import tyut.practice.onlineDisk.dao.UserDao;

public class UserService {
	private UserDao dao = new UserDao();
	/**
	 * ���ݴ�����û���(name)������(password)У���û��Ƿ�Ϸ�
	 * @param  String name��String password
	 * @return boolean
	 */
	public boolean verify(String name, String password){
		String pwd = dao.getPassWordByName(name);
		if(pwd == null){
			return false;
		}
		if(pwd.equals(password)){
			return true;
		}
		return false;
	}
	public String getNameByEmail(String email){
		String name=dao.getNameByEmail(email);
		return name;
	}
	/**
	 * ���ݴ�����û���(name),����(password),����(email)����ע��
	 * @param  String name,String password,String email
	 * @return boolean
	 */
	public boolean register(String name, String password, String email){
		if(dao.getPassWordByName(name) != null){
			return false;
		}
		return dao.addUser(name, password, email);
	}
	/**
	 * ���ݴ�����û���(name),ԭ����(passwordB),������(password)�޸��û�������
	 * @param  String name,String passwordB,String password
	 * @return boolean
	 */
	public String UpdatePsd(String name, String passwordB, String password)
	{
		System.out.println(dao.getPassWordByName(name));
		if(!dao.getPassWordByName(name).equals(passwordB)){
			return "ԭ�������";
		}
		if(dao.updatePasswordByName(name, password)==true)
			return "success";
		else 
			{
				return "fail";
			}
	}
}
